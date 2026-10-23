#include <iostream>
#include <vector>
#include <iomanip> 
int main() {
    const double v0 = 50.0;
    const double g = 9.8;
    const double dt = 1.0;
    if (v0 <= 0) {
        std::cout << "Предупреждение: Начальная скорость v0 должна быть больше нуля!" << std::endl;
        return 1;
    }

    std::vector<double> times;
    std::vector<double> heights;

    int estimated_size = static_cast<int>(v0 * 2 / g / dt);
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

    std::cout << std::setw(10) << "Время (с)" << std::setw(15) << "      Высота (м)" << std::endl;
    std::cout << "---------------------------" << std::endl;

    std::cout << std::fixed << std::setprecision(2);

    for (size_t i = 0; i < times.size(); ++i) {
        std::cout << std::setw(10) << times.at(i) 
                  << std::setw(15) << heights.at(i) << std::endl;
    }

    return 0;
}
