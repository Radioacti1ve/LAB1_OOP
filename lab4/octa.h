#pragma once
#include <iostream>
#include "functional.h"
#include "figure.h"
#include <cmath>
#include <vector>

template<typename T>
class Octa: public Figure {
public:
    double size;
    std::vector<std::pair<T, T>> coord;
    
    Octa():size(8), coord({{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}}) {}
    
    Octa(std::vector<std::pair<T, T>> coor): size(8), coord(coor) {}
    
    ~Octa() {
        size = 0;
        coord = {};
    }

    Octa<T> &operator=(const Octa<T> &other);
    Octa<T> &operator=(Octa<T> &&other);
    operator double() const override;


};

template<typename T>
inline std::istream &operator>>(std::istream &is, Octa<T> &obj) {
    
    for(int i = 0; i < 8; ++i) {
        std::cout << "Input the coordinates of point " << i + 1 << ":\nx: ";
        is >> obj.coord[i].first;
        std::cout << "y: ";
        is >> obj.coord[i].second;
    } 

    return is;
}

template<typename T>
inline std::ostream &operator<<(std::ostream &os, const Octa<T> &obj) {
    for(int i = 0; i < 8; ++i) {
        os << "Coorinates of point " << i + 1 << "[" << obj.coord[i].first << ", " << obj.coord[i].second << "]\n";
    }

    return os;
}

template<typename T>
inline bool operator==(const Octa<T> &first, const Octa<T> &second) {
    for(int i = 0; i < 8; ++i) {
        if(first.coord[i] != second.coord[i])
            return false;
    }
    return true;
}

template<typename T>
Octa<T> &Octa<T>::operator=(const Octa<T> &other) {
    coord = other.coord;
    size = other.size;
    return *this;
}

template<typename T>
Octa<T> &Octa<T>::operator=(Octa<T> &&other) {
    coord = std::move(other.coord);
    size = std::move(other.size);
    return *this;
}

template<typename T>
inline Octa<T>::operator double() const{
    return Area<Octa<T>, T>(*this);
}
