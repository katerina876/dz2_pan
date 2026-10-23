#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

int main() {
    std::cout << std::fixed << std::setprecision(2);
    const double v0 = 50.0;  
    const double g = 9.8;    
    const double dt = 1.0;   
    std::vector<double> heights;

    for (double t = 0.0; t <= 1000.0; t += dt) {
        double h = v0 * t - 0.5 * g * t * t;
        if (h < 0) {
            break;
        }
        heights.push_back(h);
    }

    auto new_end = std::remove_if(heights.begin(), heights.end(), [](double h){ return h < 10.0; });
    heights.erase(new_end, heights.end());
    std::cout << "Высота (м)" << std::endl;
    for (size_t i = 0; i < heights.size(); ++i) {
        std::cout << heights.at(i) << std::endl;
    }

    return 0;
}
