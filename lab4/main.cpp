#include <iostream>
#include <vector>
#include <cmath>
#include "array.h"
#include "figure.h"
#include "hexa.h"
#include "octa.h"
#include "penta.h"

int main() {
    std::vector<std::pair<double, double>> points_5 = {{2.0, 2.0}, {4.0, 4.0}, {2.0, 2.0}, {0.0, 0.0}, {-2.0, -2.0}};
    Penta<double> Pen(points_5);

    std::vector<std::pair<double, double>> points_6 = {{2.0, 2.0}, {4.0, 4.0}, {6.0, 6.0}, {4.0, 4.0}, {2.0, 2.0}, {0.0, 0.0}};
    Hexa<double> Hex(points_6);

    std::vector<std::pair<double, double>> points_8 = {{2.0, 2.0}, {4.0, 4.0}, {6.0, 6.0}, {8.0, 8.0}, {6.0, 6.0}, {4.0, 4.0}, {2.0, 2.0}, {0.0, 0.0}};
    Octa<double> Oct(points_8);
    std::cout << (double)Oct << std::endl << (double)Hex << std::endl << (double)Pen << std::endl;

    return 0;
}