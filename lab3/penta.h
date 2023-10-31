#pragma once
#include <iostream>
#include "figure.h"
#include <cmath>
#include <vector>

class Penta: public Figure {
public:
    Penta();
    Penta(std::vector<double> &x, std::vector<double> &y);
    ~Penta();

    double Area() const override {
        return s;
    }

    coordinates rotation_point() const override {
        coordinates mid;
        mid.x = midlle_x;
        mid.y = midlle_y;
        return mid;
    }

    operator double() const override {
        return s;
    }

    friend std::ostream &operator<<(std::ostream &os, const Penta &obj);
    friend std::istream &operator>>(std::istream &is, Penta &obj);

    bool operator==(Penta &other) const;
    Penta &operator=(Penta &other);
    Penta &operator=(Penta &&other);

    

private:
    int n;
    double midlle_x;
    double midlle_y;
    double s;
    std::vector<double> x_coor;
    std::vector<double> y_coor;
};

inline std::istream &operator>>(std::istream &is, Penta &obj) {
    double x, y;
    std::vector<double> coor_x(5), coor_y(5);
    for(int i = 0; i < 5; ++i) {
        std::cout << "Input the coordinates of point " << i + 1 << ":\n x: ";
        is >> x;
        std::cout << "y: ";
        is >> y;
        coor_x[i] = x;
        coor_y[i] = y;
    } 
    obj = Penta(coor_x, coor_y);
    return is;
}

inline std::ostream &operator<<(std::ostream &os, const Penta &obj) {
    for(int i = 0; i < 5; ++i) {
        os << "Coorinates of point " << i + 1 << "[" << obj.x_coor[i] << ", " << obj.y_coor[i] << "]\n";
    }

    return os;
}
