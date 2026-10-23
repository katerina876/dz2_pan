#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::cout << std::fixed << std::setprecision(2);
    std::vector<double> h = {10.0, 25.0, 42.0, 55.0, 48.0, 31.0, 12.0};
    size_t n = h.size();
    std::vector<double> smoothed(n);
    for (size_t i = 1; i + 1 < n; ++i) {
        smoothed[i] = (h[i - 1] + h[i] + h[i + 1]) / 3.0;
    }

    smoothed[0] = h[0];
    smoothed[n - 1] = h[n - 1];
    std::cout << std::setw(15) << "         Исходный" << std::setw(15) << "      Сглаженный" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    for (size_t i = 0; i < n; ++i) {
        std::cout << std::setw(15) << h[i] << std::setw(15) << smoothed[i] << std::endl;
    }

    return 0;
}
