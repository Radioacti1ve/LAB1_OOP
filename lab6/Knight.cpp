#include "Squirrel.hpp"
#include "Knight.hpp"
#include "SlaveSaler.hpp"
#include <algorithm>

Knight::Knight(const int& x, const int& y, const std::string& name) {
    this->x = x;
    this->y = y;
    this->name = name;
    alive = true;
}

void Knight::print(std::ostream& out) {
    out << *this;
}

void Knight::accept(NPC* attacker, const int& distance) {
    std::cout << "God!!!!!\n";
}

std::ostream& operator<<(std::ostream& out, const Knight& other) {
    return out << "Knight " << other.name << " {" << other.x << ", " << other.y << '}';
}