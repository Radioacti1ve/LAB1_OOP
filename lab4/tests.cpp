#include <gtest/gtest.h>
#include "functional.h"
#include "array.h"
#include "penta.h"
#include "hexa.h"
#include "octa.h"

TEST(Penta, empty_constructor)
{
    Penta<double> p;
    std::pair<double, double> dot = {0, 0};
    std::pair<double, double> time = middle<Penta<double>, double>(p);
    double surf = Area<Penta<double>, double>(p);
    EXPECT_EQ(time, dot);
    EXPECT_EQ(0, surf);
}

TEST(Penta, vect_const)
{
    std::vector<double> x{1, 2, 3, 1, 2};
    std::vector<double> y{1, 2, 3, 1, 2};
    std::vector<std::pair<double, double>> five(5);
    for (int i = 0; i < 5; ++i)
    {
        five[i].first = x[i];
        five[i].second = y[i];
    }
    Penta<double> p(five);

    std::pair<double, double> dot = {1.8, 1.8};
    std::pair<double, double> time = middle<Penta<double>, double>(p);
    EXPECT_EQ(time, dot);
}


TEST(Hexa, empty)
{
    Hexa<double> p;
    std::pair<double, double> dot = {0, 0};
    std::pair<double, double> time = middle<Hexa<double>, double>(p);
    double surf = Area<Hexa<double>, double>(p);
    EXPECT_EQ(time, dot);
    EXPECT_EQ(0, surf);
}

TEST(Hexa, vect_const)
{
    std::vector<double> x{1, 2, 3, 1, 2, 3};
    std::vector<double> y{1, 2, 3, 1, 2, 3};
    std::vector<std::pair<double, double>> six(6);
    for (int i = 0; i < 6; ++i)
    {
        six[i].first = x[i];
        six[i].second = y[i];
    }
    Hexa p(six);

    std::pair<double, double> dot = {2, 2};
    std::pair<double, double> time = middle<Hexa<double>, double>(p);
    EXPECT_EQ(time, dot);
}


TEST(Octa, empty)
{
    Octa<double> p;
    std::pair<double, double> dot = {0, 0};
    std::pair<double, double> time = middle<Octa<double>, double>(p);
    double surf = Area<Octa<double>, double>(p);
    EXPECT_EQ(time, dot);
    EXPECT_EQ(surf, 0);
}

TEST(Octa, vect_const)
{
    std::vector<double> x{1, 2, 3, 1, 2, 3, 1, 2};
    std::vector<double> y{1, 2, 3, 1, 2, 3, 1, 2};
    std::vector<std::pair<double, double>> eight(8);
    for (int i = 0; i < 8; ++i)
    {
        eight[i].first = x[i];
        eight[i].second = y[i];
    }
    Octa<double> p(eight);

    std::pair<double, double> dot = {1.875, 1.875};
    std::pair<double, double> time = middle<Octa<double>, double>(p);
    EXPECT_EQ(time, dot);
}

TEST(Array, common_Area)
{
    Array<Penta<double>> a(2);
    Penta<double> *p1 = new Penta<double>();
    Penta<double> *p2 = new Penta<double>();
    a[0] = *p1;
    a[1] = *p2;
    EXPECT_EQ(a.common_area(), 0.0);
}