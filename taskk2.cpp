#include <iostream>
#include <vector>
#include <iomanip> 
#include <cmath>

int main() {
    std::cout << std::fixed << std::setprecision(2);
    const double v0 = 50.0;  
    const double g = 9.8;
    const double dt = 1.0;   
    std::vector<double> times;
    std::vector<double> heights;
    int estimated_size = v0 * 2 / g / dt;
    times.reserve(estimated_size);
    heights.reserve(estimated_size);

    for (double t = 0.0; t <= 1000.0; t += dt) {
        double h = v0 * t - 0.5 * g * t * t;
        if (h < 0) {
            break;
        }
        times.push_back(t);
        heights.push_back(h);
    }

    if (heights.empty()) {
        std::cout << "Данных нет" << std::endl;
        return 1;
    }
    size_t idx_max = 0; 
    for (size_t i = 1; i < heights.size(); ++i) {
        if (heights[i] > heights[idx_max]) {
            idx_max = i;
        }
    }
    std::cout << "Результат\n";
    std::cout << "Индекс максимальной высоты: " << idx_max << "\n";
    std::cout << "Максимальная высота: " << std::setw(8) << heights[idx_max] << " м\n";
    std::cout << "Соответствующее время: " << std::setw(8) << times[idx_max] << " с\n";

    return 0;
}