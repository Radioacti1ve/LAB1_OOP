#pragma once
#include<iostream>

struct coordinates {
    double x, y;
};

class Figure
{
    
protected:
    Figure() = default;

public:
    virtual ~Figure() = default;
    virtual double Area() const = 0;
    virtual coordinates rotation_point() const = 0;
    virtual operator double() const = 0;
};

