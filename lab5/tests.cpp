#include <gtest/gtest.h>
#include <list>
#include "list.hpp"
#include "allocator.hpp"

TEST(Test1, BasicOperations) {

    List<int, Allocator<int, 10>> mylist;
    
    mylist.push_back(1);
    mylist.front_push(2);

    EXPECT_EQ(mylist.get_size(), 2);

    mylist.pop_back();
    mylist.front_pop();

    EXPECT_EQ(mylist.get_size(), 0);
    EXPECT_TRUE(mylist.begin() == mylist.end());
}

TEST(Test2, InsertAndRemoveAtIndex) {
    List<int, Allocator<int, 10>> mylist;

    mylist.add(1, 0);
    EXPECT_EQ(mylist.get_size(), 1);
    EXPECT_EQ(*mylist.begin(), 1);  

    mylist.add(2, 1);
    EXPECT_EQ(mylist.get_size(), 2);

    mylist.add(3, 1);
    EXPECT_EQ(mylist.get_size(), 3);
    EXPECT_EQ(*mylist.begin(), 1);

    mylist.cut(1);
    EXPECT_EQ(mylist.get_size(), 2);
    EXPECT_EQ(*mylist.begin(), 1);
    mylist.cut(0);
    EXPECT_EQ(mylist.get_size(), 1);
    EXPECT_EQ(*mylist.begin(), 1);
}

TEST(Test3, IteratorAndAllocator) {
    List<int, Allocator<int, 10>> mylist;

    EXPECT_TRUE(mylist.begin() == mylist.end());

    mylist.push_back(1);
    mylist.front_push(2);
    mylist.push_back(3);

    int sum = 0;
    for (auto it = mylist.begin(); it != mylist.end(); ++it) {
        sum += *it;
    }

    EXPECT_EQ(sum, 6);
    EXPECT_EQ(mylist.get_size(), 3);
}

TEST(Test4, PushBackAndFrontPush) {
    List<int, Allocator<int, 10>> mylist;

    mylist.push_back(1);
    mylist.front_push(2);
    mylist.push_back(3);

    EXPECT_EQ(mylist.get_size(), 3);
    EXPECT_EQ(*mylist.begin(), 2);
}

TEST(Test5, RemoveFromEmptyList) {
    List<int, Allocator<int, 10>> mylist;

    mylist.cut(0);

    EXPECT_EQ(mylist.get_size(), 0);
    EXPECT_TRUE(mylist.begin() == mylist.end());
}

