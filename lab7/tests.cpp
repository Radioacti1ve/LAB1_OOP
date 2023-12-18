#include <gtest/gtest.h>
#include <memory>
#include "npc.hpp"
#include "Squirrel.hpp"
#include "Knight.hpp"
#include "SlaveSaler.hpp"

TEST(test_01, Squirrel_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Squirrel>(x, y);

    EXPECT_EQ((a->position()).first,100);
}

TEST(test_02, Squirrel_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Squirrel>(x, y);
    EXPECT_EQ(SquirrelType,a->get_type());
}

TEST(test_03, Squirrel_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Squirrel>(x, y);
    EXPECT_TRUE(a->is_alive());
}



TEST(test_04, Knight_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Knight>(x, y);

    EXPECT_EQ((a->position()).first,100);
}

TEST(test_05, Knight_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Knight>(x, y);
    EXPECT_EQ(KnightType,a->get_type());
}

TEST(test_06, Knight_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Knight>(x, y);
    EXPECT_TRUE(a->is_alive());
}


TEST(test_07, Knight_constructor){
    int x{10};
    int y{10};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Knight>(x, y);

    a->move(50,50,100,100);
    EXPECT_EQ((a->position()).first,60);
}


TEST(test_08, SlaveSaler_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<SlaveSaler>(x, y);

    EXPECT_EQ((a->position()).second,100);
}

TEST(test_09, SlaveSaler_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<SlaveSaler>(x, y);
    EXPECT_EQ(SlaveSalerType,a->get_type());
}

TEST(test_10, SlaveSaler_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<SlaveSaler>(x, y);
    EXPECT_TRUE(a->is_alive());
}
