#include <gtest/gtest.h>
#include "array.h"
#include "penta.h"
#include "hexa.h"
#include "octa.h"

TEST(Penta, empty_constructor)
{
    Penta p;
    coordinates dot;
    dot.x = 0, dot.y = 0;
    coordinates time = p.rotation_point();
    EXPECT_EQ(time.x, dot.x);
    EXPECT_EQ(time.y, dot.y);
    EXPECT_EQ(p.Area(), 0);
}

TEST(Penta, vect_const)
{
    std::vector<double> x{1, 2, 3, 1, 2};
    std::vector<double> y{1, 2, 3, 1, 2};
    Penta p(x, y);

    coordinates dot;
    dot.x = 1.8, dot.y = 1.8;
    coordinates time = p.rotation_point();
    EXPECT_EQ(time.x, dot.x);
    EXPECT_EQ(time.y, dot.y);
}

TEST(Penta, equal)
{
    std::vector<double> x{1, 2, 3, 1, 2};
    std::vector<double> y{1, 2, 3, 1, 2};
    Penta p1(x, y), p2(x, y);
    EXPECT_EQ(p1, p2);
}


TEST(Hexa, empty)
{
    Hexa p;
    coordinates dot;
    dot.x = 0, dot.y = 0;
    coordinates time = p.rotation_point();
    EXPECT_EQ(time.x, dot.x);
    EXPECT_EQ(time.y, dot.y);
    EXPECT_EQ(p.Area(), 0);
}

TEST(Hexa, vect_const)
{
    std::vector<double> x{1, 2, 3, 1, 2, 3};
    std::vector<double> y{1, 2, 3, 1, 2, 3};
    Hexa p(x, y);

    coordinates dot;
    dot.x = 2, dot.y = 2;
    coordinates time = p.rotation_point();
    EXPECT_EQ(time.x, dot.x);
    EXPECT_EQ(time.y, dot.y);
}

TEST(Hexa, equal)
{
    std::vector<double> x{1, 2, 3, 1, 2, 3};
    std::vector<double> y{1, 2, 3, 1, 2, 3};
    Hexa p1(x, y), p2(x, y);
    EXPECT_EQ(p1, p2);
}


TEST(Octa, empty)
{
    Octa p;
    coordinates dot;
    dot.x = 0, dot.y = 0;
    coordinates time = p.rotation_point();
    EXPECT_EQ(time.x, dot.x);
    EXPECT_EQ(time.y, dot.y);
    EXPECT_EQ(p.Area(), 0);
}

TEST(Octa, vect_const)
{
    std::vector<double> x{1, 2, 3, 1, 2, 3, 1, 2};
    std::vector<double> y{1, 2, 3, 1, 2, 3, 1, 2};
    Octa p(x, y);

    coordinates dot;
    dot.x = 1.875, dot.y = 1.875;
    coordinates time = p.rotation_point();
    EXPECT_EQ(time.x, dot.x);
    EXPECT_EQ(time.y, dot.y);
}

TEST(Octa, equal)
{
    std::vector<double> x{1, 2, 3, 1, 2, 3, 1, 2};
    std::vector<double> y{1, 2, 3, 1, 2, 3, 1, 2};
    Octa p1(x, y), p2(x, y);
    EXPECT_EQ(p1, p2);
}


TEST(Array, empty)
{
    Array a;

    for (int i = 0; i != 1; ++i)
        EXPECT_EQ(a[i], nullptr);
}

TEST(Array, size_conrtuctor)
{
    Array a(15);

    EXPECT_EQ(a.Get_Size(), 15);

    for (int i = 0; i != 15; ++i)
        EXPECT_EQ(a[i], nullptr);
}