#include "Squirrel.hpp"
#include "Knight.hpp"
#include "SlaveSaler.hpp"
#include <algorithm>

SlaveSaler::SlaveSaler(const int& x, const int& y, const std::string& name) {
    this->x = x;
    this->y = y;
    this->name = name;
    alive = true;
}

void SlaveSaler::print(std::ostream& out) {
    out << *this;
}

void SlaveSaler::accept(NPC* attacker, const int& distance) {
    if (alive && dynamic_cast<Knight*>(attacker) && attacker != this) {
        bool win = is_close(*attacker, distance);
        if (win) 
            alive = false;
        notify(attacker, win);
    }
}

std::ostream& operator<<(std::ostream& out, const SlaveSaler& other) {
    return out << "SlaveSaler " << other.name << " {" << other.x << ", " << other.y << '}';
}