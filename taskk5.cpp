#include <iostream>
#include <vector>
#include <iomanip>

struct Point { 
    double x, y, z; 
};

int main() {
    std::cout << std::fixed << std::setprecision(2);
    const double vx = 30.0;
    const double vy = 20.0;
    const double vz = 40.0;
    const double dt = 1.0;
    const double t_max = 10.0;
    std::vector<Point> traj;
    int estimated_size = (t_max / dt) + 1;
    traj.reserve(estimated_size);
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
    std::cout << std::setw(8) << "t" 
              << std::setw(12) << "x" 
              << std::setw(12) << "y" 
              << std::setw(12) << "z" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    for (double t = 0.0; t <= t_max; t += dt) {
        traj.push_back({x, y, z});
        std::cout << std::setw(8) << t 
                  << std::setw(12) << x 
                  << std::setw(12) << y 
                  << std::setw(12) << z << std::endl;
        x += vx * dt;
        y += vy * dt;
        z += vz * dt;
    }

    return 0;
}
