#include <iostream>
#include <vector>
#include <cmath>
#include "array.h"
#include "figure.h"
#include "hexa.h"
#include "octa.h"
#include "penta.h"

int main() {
    std::vector<double>x_5 {2.0, 2 * cos(72), 2 * cos(144), 2 * cos(216), 2 * cos(288)};
    std::vector<double>y_5 {0.0, 2 * sin(72), 2 * sin(144), 2 * sin(216), 2 * sin(288)};
    Penta Pen(x_5, y_5);

    std::vector<double>x_6 {2.0, 2 * cos(60), 2 * cos(120), 2 * cos(180), 2 * cos(240), 2 * cos(300)};
    std::vector<double>y_6 {2.0, 2 * sin(60), 2 * sin(120), 2 * sin(180), 2 * sin(240), 2 * sin(300)};
    Hexa Hex(x_6, y_6);

    std::vector<double>x_8 {2.0, 2 * cos(45), 2 * cos(90), 2 * cos(135), 2 * cos(180), 2 * cos(225), 2 * cos(270), 2 * cos(315)};
    std::vector<double>y_8 {0.0, 2 * sin(45), 2 * sin(90), 2 * sin(135), 2 * sin(180), 2 * sin(225), 2 * sin(270), 2 * sin(315)};
    Octa Oct(x_8, y_8);
    double Area_5 = Pen;
    double Area_6 = Hex;
    double Area_8 = Oct;
    std::cout << "Area_5: " << Area_5 << "\n" << "Area_6: " << Area_6 << "\n" << "Area_8: " << Area_8 << "\n";

    Array Arr = Array(3);
    Arr.add(&Pen, 0);
    Arr.add(&Hex, 1);
    Arr.add(&Oct, 2);
    std::cout << Arr.Get_Size() << "\n";


}