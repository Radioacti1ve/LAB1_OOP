#include "Squirrel.hpp"
#include "Knight.hpp"
#include "SlaveSaler.hpp"
#include <algorithm>

Squirrel::Squirrel(const int& x, const int& y, const std::string& name) {
    this->x = x;
    this->y = y;
    this->name = name;
    alive = true;
}

void Squirrel::print(std::ostream& out) {
    out << *this;
}

void Squirrel::accept(NPC* attacker, const int& distance) {
    if (alive && dynamic_cast<Squirrel*>(attacker)) {
        bool win = is_close(*attacker, distance);
        if (win) 
            alive = false;
        notify(attacker, win);
    }

    if (alive && dynamic_cast<SlaveSaler*>(attacker) && attacker!= this) {
        bool win = is_close(*attacker, distance);
        if (win) 
            alive = false;
        notify(attacker, win);
    }
}

std::ostream& operator<<(std::ostream& out, const Squirrel& other) {
    return out << "Squirrel " << other.name << " {" << other.x << ", " << other.y << '}';
}