#pragma once
#include<iostream>

class Figure
{
protected:
    Figure() = default;

public:
    virtual ~Figure() = default;
    virtual operator double() const = 0;
};

