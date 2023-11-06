#include <string>
#include <vector>
#include <cmath>
#include "hexa.h"

Hexa::Hexa():
    midlle_x(0),
    midlle_y(0),
    s(0),
    x_coor({0.0, 0.0, 0.0, 0.0, 0.0, 0.0}),
    y_coor({0.0, 0.0, 0.0, 0.0, 0.0, 0.0})

{

}

Hexa::Hexa(std::vector<double> &x, std::vector<double> &y): midlle_x(0), midlle_y(0), n(6) {
    if (x_coor.size() != n)
    {
        x_coor.resize(n);
    }

    if (y_coor.size() != n)
    {
        y_coor.resize(n);
    }
    for(int i = 0; i < n; ++i) {
        midlle_x += x[i];
        midlle_y += y[i];
        x_coor[i] = x[i];
        y_coor[i] = y[i];
    }
    midlle_x /= n;
    midlle_y /= n;
    double rib = std::sqrt(std::pow(x[0] - x[1], 2) + std::pow(y[0] - y[1], 2));
    s = rib * rib * 3 * std::sqrt(3) /2;

}

Hexa::~Hexa() {
    midlle_x = 0;
    midlle_y = 0;
    x_coor = {};
    y_coor = {};
    s = 0;
}

bool Hexa::operator==(Hexa &other) const {
    return s == other.s;
}

Hexa &Hexa::operator=(Hexa &other) {
    x_coor = other.x_coor;
    y_coor = other.y_coor;
    midlle_x = other.midlle_x;
    midlle_y = other.midlle_y;
    s = other.s;
    return *this;
}

Hexa &Hexa::operator=(Hexa &&other) {
    x_coor = std::move(other.x_coor);
    y_coor = std::move(other.y_coor);
    midlle_x = std::move(other.midlle_x);
    midlle_y = std::move(other.midlle_y);
    s = std::move(other.s);
    return *this;
}