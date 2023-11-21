#pragma once
#include <iostream>
#include "functional.h"
#include "figure.h"
#include <cmath>
#include <vector>

template<typename T>
class Penta: public Figure {
public:
    double size;
    std::vector<std::pair<T, T>> coord;
    
    Penta():size(5), coord({{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}}) {}
    
    Penta(std::vector<std::pair<T, T>> coor): size(5), coord(coor) {}
    
    ~Penta() {
        size = 0;
        coord = {};
    }

    Penta<T> &operator=(const Penta<T> &other);
    Penta<T> &operator=(Penta<T> &&other);
    operator double() const override;


};

template<typename T>
inline std::istream &operator>>(std::istream &is, Penta<T> &obj) {
    
    for(int i = 0; i < 5; ++i) {
        std::cout << "Input the coordinates of point " << i + 1 << ":\nx: ";
        is >> obj.coord[i].first;
        std::cout << "y: ";
        is >> obj.coord[i].second;
    } 

    return is;
}

template<typename T>
inline std::ostream &operator<<(std::ostream &os, const Penta<T> &obj) {
    for(int i = 0; i < 5; ++i) {
        os << "Coorinates of point " << i + 1 << "[" << obj.coord[i].first << ", " << obj.coord[i].second << "]\n";
    }

    return os;
}

template<typename T>
inline bool operator==(const Penta<T> &first, const Penta<T> &second) {
    for(int i = 0; i < 5; ++i) {
        if(first.coord[i] != second.coord[i])
            return false;
    }
    return true;
}

template<typename T>
Penta<T> &Penta<T>::operator=(const Penta<T> &other) {
    coord = other.coord;
    size = other.size;
    return *this;
}

template<typename T>
Penta<T> &Penta<T>::operator=(Penta<T> &&other) {
    coord = std::move(other.coord);
    size = std::move(other.size);
    return *this;
}

template<typename T>
inline Penta<T>::operator double() const{
    return Area<Penta<T>, T>(*this);
}
