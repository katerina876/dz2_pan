#include <iostream>
#include <vector>
#include <iomanip>

struct Point {
    double x, y, z;
};

class Rocket {
private:
    double mass;
    double vx, vy, vz;
    double x, y, z;

public:
    Rocket(double m, double vx0, double vy0, double vz0) 
        : mass(m), vx(vx0), vy(vy0), vz(vz0), x(0.0), y(0.0), z(0.0) {}

    void updatePosition(double dt) {
        x += vx * dt;
        y += vy * dt;
        z += vz * dt;
    }

    void changeVelocity(double dvx, double dvy, double dvz) {
        vx += dvx;
        vy += dvy;
        vz += dvz;
    }

    Point getPosition() const {
        return {x, y, z};
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(2);
    std::vector<Rocket> squad;
    squad.reserve(5);
    squad.emplace_back(1000, 10, 0, 50);
    squad.emplace_back(900, 15, -5, 40);
    squad.emplace_back(1100, 12, 5, 45);
    squad.emplace_back(950, 8, -2, 55);
    squad.emplace_back(1050, 14, 3, 35);
    std::vector<std::vector<Point>> trajectories(5);
    const double dt = 1.0;
    const double T = 10.0;

    for (double t = 0.0; t <= T; t += dt) {
        for (size_t i = 0; i < squad.size(); ++i) {
            trajectories[i].push_back(squad[i].getPosition());
            squad[i].updatePosition(dt);
        }
    }

    std::cout << std::setw(10) << "     Ракета" 
              << std::setw(15) << "      Конечный X" 
              << std::setw(15) << "      Конечный Y" 
              << std::setw(15) << "      Конечный Z" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    for (size_t i = 0; i < squad.size(); ++i) {
        Point pos = squad[i].getPosition();
        std::cout << std::setw(10) << i + 1 
                  << std::setw(15) << pos.x 
                  << std::setw(15) << pos.y 
                  << std::setw(15) << pos.z << std::endl;
    }

    return 0;
}
