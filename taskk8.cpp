#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>

int main() {
    std::cout << std::fixed << std::setprecision(2);
    std::vector<double> times1 = {0.0, 1.0, 2.0, 3.0, 4.0};
    std::vector<double> heights1 = {0.0, 30.0, 45.0, 20.0, -5.0};
    std::vector<double> times2 = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> heights2 = {0.0, 35.0, 55.0, 40.0, 15.0, -2.0};
    auto it_max1 = std::max_element(heights1.begin(), heights1.end());
    double max1 = *it_max1;
    double t_max1 = times1[std::distance(heights1.begin(), it_max1)];
    auto it_fall1 = std::find_if(heights1.begin() + 1, heights1.end(), [](double h){ return h <= 0.0; });
    double t_fall1 = (it_fall1 != heights1.end()) ? times1[std::distance(heights1.begin(), it_fall1)] : times1.back();
    auto it_max2 = std::max_element(heights2.begin(), heights2.end());
    double max2 = *it_max2;
    double t_max2 = times2[std::distance(heights2.begin(), it_max2)];
    auto it_fall2 = std::find_if(heights2.begin() + 1, heights2.end(), [](double h){ return h <= 0.0; });
    double t_fall2 = (it_fall2 != heights2.end()) ? times2[std::distance(heights2.begin(), it_fall2)] : times2.back();
    std::cout << std::setw(12) << "Объект" << std::setw(15) << "          max_height" << std::setw(15) << "        time_of_max" << std::setw(15) << "        time_of_fall" << std::endl;
    std::cout << std::setw(12) << "Ракета 1" << std::setw(15) << max1 << std::setw(15) << t_max1 << std::setw(15) << t_fall1 << std::endl;
    std::cout << std::setw(12) << "Ракета 2" << std::setw(15) << max2 << std::setw(15) << t_max2 << std::setw(15) << t_fall2 << std::endl;
    std::cout << "Выше поднялась: " << (max1 > max2 ? "Ракета 1" : "Ракета 2") << std::endl;
    std::cout << "Дольше летела: " << (t_fall1 > t_fall2 ? "Ракета 1" : "Ракета 2") << std::endl;

    return 0;
}
