#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::cout << std::fixed << std::setprecision(2);
    const double v0 = 50.0; 
    const double g = 9.8;      
    const double dt = 1.0;     
    const double t_max = (v0 * 2.0) / g; 
    std::vector<double> times;
    std::vector<double> velocities;
    int estimated_size = (v0 * 2.0) / g / dt;
    times.reserve(estimated_size);
    velocities.reserve(estimated_size);

    for (double t = 0.0; t <= t_max; t += dt) {
        double v = v0 - g * t;
        times.push_back(t);
        velocities.push_back(v);
    }

    std::cout << std::setw(10) << "Время (с)" << std::setw(15) << "     Скорость (м/с)" << std::endl;
    std::cout << "---------------------------" << std::endl;

    for (size_t i = 0; i < times.size(); ++i) {
        std::cout << std::setw(10) << times.at(i) 
                  << std::setw(15) << velocities.at(i) << std::endl;
    }

    double t_zero_velocity = v0 / g;
    std::cout << "---------------------------" << std::endl;
    std::cout << "Точный момент остановки в наивысшей точке: " << t_zero_velocity << " с" << std::endl;

    return 0;
}
