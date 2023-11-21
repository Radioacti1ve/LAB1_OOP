#pragma once
#include <iostream>
#include "functional.h"
#include "figure.h"
#include <cmath>
#include <vector>

template<typename T>
class Hexa: public Figure {
public:
    double size;
    std::vector<std::pair<T, T>> coord;
    
    Hexa():size(6), coord({{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}}) {}
    
    Hexa(std::vector<std::pair<T, T>> coor): size(6), coord(coor) {}
    
    ~Hexa() {
        size = 0;
        coord = {};
    }

    Hexa<T> &operator=(const Hexa<T> &other);
    Hexa<T> &operator=(Hexa<T> &&other);
    operator double() const override;


};

template<typename T>
inline std::istream &operator>>(std::istream &is, Hexa<T> &obj) {
    
    for(int i = 0; i < 6; ++i) {
        std::cout << "Input the coordinates of point " << i + 1 << ":\nx: ";
        is >> obj.coord[i].first;
        std::cout << "y: ";
        is >> obj.coord[i].second;
    } 

    return is;
}

template<typename T>
inline std::ostream &operator<<(std::ostream &os, const Hexa<T> &obj) {
    for(int i = 0; i < 6; ++i) {
        os << "Coorinates of point " << i + 1 << "[" << obj.coord[i].first << ", " << obj.coord[i].second << "]\n";
    }

    return os;
}

template<typename T>
inline bool operator==(const Hexa<T> &first, const Hexa<T> &second) {
    for(int i = 0; i < 6; ++i) {
        if(first.coord[i] != second.coord[i])
            return false;
    }
    return true;
}

template<typename T>
Hexa<T> &Hexa<T>::operator=(const Hexa<T> &other) {
    coord = other.coord;
    size = other.size;
    return *this;
}

template<typename T>
Hexa<T> &Hexa<T>::operator=(Hexa<T> &&other) {
    coord = std::move(other.coord);
    size = std::move(other.size);
    return *this;
}

template<typename T>
inline Hexa<T>::operator double() const{
    return Area<Hexa<T>, T>(*this);
}
