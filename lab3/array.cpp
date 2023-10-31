#include <iostream>
#include <cmath>
#include "array.h"

Array::Array() {
    _size = 1;
    _figures = new Figure*[_size];
    for(int i = 0; i < _size; ++i) {
        _figures[i] = nullptr;
    }
}

Array::Array(int size) {
    _size = size;
    _figures = new Figure*[_size];
    for(int i = 0; i < _size; ++i) {
        _figures[i] = nullptr;
    }
}

Array::~Array() {
    for(int i = 0; i < _size; ++i) {
        if(_figures[i] != nullptr) {
            delete _figures[i];
        }
    }
    delete[] _figures;
    _figures = nullptr;
    _size = 0;
}

Figure *Array::operator[](int index) const{
    if(index >= _size) {
        throw std::invalid_argument(" Index >= size");
    }

    return _figures[index];
}

void Array::del(int index) {
    if(index >= _size) {
        throw std::invalid_argument("Index >= size");
    }
    delete _figures[index];
    _figures[index] = nullptr;
}

void Array::change(Figure *fig, int index) {
    if(index >= _size) {
        throw std::invalid_argument("Index >= size");
    }
    if(_figures[index] != nullptr) {
        delete _figures[index];
    }
    _figures[index] = fig;
}

double Array::Area() {
    double result = 0;
    for(int i = 0; i < _size; ++i) {
        if(_figures[i] != nullptr) {
            result += (double)*_figures[i];
        }
    }
}





