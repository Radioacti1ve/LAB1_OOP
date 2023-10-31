#include "figure.h"

class Array
{
private:
    Figure **_figures;
    int _size;
public:
    Array();
    ~Array();
    Array(int size);
    
    void add(Figure *fig, int index);
    void del(int index);
    Figure *operator[](int index) const;
    void change(Figure *fig, int index);
    double Area();
};

