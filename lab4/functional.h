#pragma once
#include <cmath>
#include <iostream>

template<class A, typename T>
std::pair<T, T> middle(A &fig) {
    double size = fig.size;
    std::pair<T, T> tmp = {0, 0};
    for(std::pair<T, T> points: fig.coord) {
        tmp.first += points.first;
        tmp.second += points.second;
    }
    tmp.first /= size;
    tmp.second /= size;
    return tmp;
}

template<class A, typename T>
T Area(const A &fig) {
    double size = fig.size;
    std::pair<T, T> fcoord = fig.coord[0];
    std::pair<T, T> scoord = fig.coord[1];
    T lenght = std::sqrt(std::pow(fcoord.first - scoord.first, 2) + std::pow(fcoord.second - scoord.second, 2));
    return std::abs(size * lenght * lenght / (4 * std::tan(180/size)));
}

