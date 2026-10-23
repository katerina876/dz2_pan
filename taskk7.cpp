#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>

int main() {
    std::cout << std::fixed << std::setprecision(2);
    const double v0 = 50.0;  
    const double g = 9.8;    
    const double dt = 1.0;   
    std::vector<double> times;
    std::vector<double> heights;

    for (double t = 0.0; t <= 1000.0; t += dt) {
        double h = v0 * t - 0.5 * g * t * t;
        times.push_back(t);
        heights.push_back(h);
        if (h < 0) {
            break;
        }
    }
    auto it = std::find_if(heights.begin(), heights.end(), [](double h){ return h <= 0.0; });

    if (it == heights.end()) {
        std::cout << "Падения не было в диапазоне" << std::endl;
    } else {
        size_t idx = std::distance(heights.begin(), it);
        double t_fall = times[idx];

        std::cout << "Время падения: " << t_fall << " с" << std::endl;
        std::cout << "Высота в этот момент: " << heights[idx] << " м" << std::endl;
    }

    return 0;
}
