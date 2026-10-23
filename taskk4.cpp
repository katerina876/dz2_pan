#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>

int main() {
    std::cout << std::fixed << std::setprecision(2);
    const double v0 = 50.0;    
    const double g = 9.8;      
    const double dt = 1.0;     
    const double t_max = (v0 * 2.0) / g; 
    std::vector<double> times;
    std::vector<double> velocities;

    for (double t = 0.0; t <= t_max; t += dt) {
        double v = v0 - g * t;
        times.push_back(t);
        velocities.push_back(v);
    }

    if (velocities.empty()) {
        std::cout << "Пусто" << std::endl;
        return 1;
    }

    double sum = std::accumulate(velocities.begin(), velocities.end(), 0.0);
    double avg = sum / velocities.size();
    std::cout << "Средняя скорость: " << avg << " м/с" << std::endl;
    return 0;
}
