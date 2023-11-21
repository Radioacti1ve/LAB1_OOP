#pragma once
#include "functional.h"
#include "figure.h"
#include <memory>


template<typename T>
class Array
{
public:
    Array() {
        array_size = 0;
        my_ptr = nullptr;
    }
    ~Array() {
        array_size = 0;
        my_ptr = nullptr;
    }
    Array(int size) {
        array_size = size;
        my_ptr = std::shared_ptr<T[]>(new T[size]);
    }
    
    T &operator[](int index) {
        return my_ptr[index];
    }

    double common_area() {
        double tmp = 0;
        for(int i = 0; i < array_size; ++i) {
            tmp += (double)my_ptr[i];
        }
        return tmp;
    }

private:
    int array_size;
    std::shared_ptr<T[]> my_ptr;
};

