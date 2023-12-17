#include <gtest/gtest.h>
#include <sstream>
#include <vector>
#include <memory>
#include "Knight.hpp"
#include "SlaveSaler.hpp"
#include "Squirrel.hpp"
#include "factory.hpp"

TEST(Constructors, Knight) {
    Knight k(3, 3, "Sir Knightly");
    std::stringstream out;
    k.print(out);
    ASSERT_EQ(out.str(), "Knight Sir Knightly {3, 3}");
}

TEST(Constructors, SlaveSaler) {
    SlaveSaler ss(4, 4, "Slave Trader");
    std::stringstream out;
    ss.print(out);
    ASSERT_EQ(out.str(), "SlaveSaler Slave Trader {4, 4}");
}

TEST(Constructors, Squirrel) {
    Squirrel sq(5, 5, "Nutty");
    std::stringstream out;
    sq.print(out);
    ASSERT_EQ(out.str(), "Squirrel Nutty {5, 5}");
}

TEST(Fabric, additional) {
    std::vector<std::shared_ptr<NPC>> persons;
    persons.push_back(factory("Knight", "Sir Knightly", 3, 3));
    persons.push_back(factory("SlaveSaler", "Slave Trader", 4, 4));
    persons.push_back(factory("Squirrel", "Nutty", 5, 5));

    std::stringstream out;
    for (auto& elem : persons) {
        elem->print(out);
    }
    ASSERT_EQ(out.str(), "Knight Sir Knightly {3, 3}SlaveSaler Slave Trader {4, 4}Squirrel Nutty {5, 5}");
}



TEST(Fighting, knight_vs_knight) {
    std::vector<std::shared_ptr<NPC>> persons;
    persons.push_back(factory("Knight", "Sir Knightly 1", 3, 3));
    persons.push_back(factory("Knight", "Sir Knightly 2", 4, 4));

    persons[0]->accept(persons[1].get(), 0);
    persons[1]->accept(persons[0].get(), 0);

    for (auto& elem : persons) {
        ASSERT_TRUE(elem->is_alive());
    }
}

TEST(Fighting, slave_saler_vs_knight) {
    std::vector<std::shared_ptr<NPC>> persons;
    persons.push_back(factory("SlaveSaler", "Slave Trader", 3, 3));
    persons.push_back(factory("Knight", "Sir Knightly", 4, 4));

    persons[0]->accept(persons[1].get(), 0);

    for (auto& elem : persons) {
        ASSERT_TRUE(elem->is_alive());
    }
}

TEST(Fighting, squirrel_vs_slave_saler) {
    std::vector<std::shared_ptr<NPC>> persons;
    persons.push_back(factory("Squirrel", "Nutty", 3, 3));
    persons.push_back(factory("SlaveSaler", "Slave Trader", 4, 4));

    persons[0]->accept(persons[1].get(), 0);

    for (auto& elem : persons) {
        ASSERT_TRUE(elem->is_alive());
    }
}



int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
