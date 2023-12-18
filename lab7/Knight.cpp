#include "Squirrel.hpp"
#include "Knight.hpp"
#include "SlaveSaler.hpp"
#include <algorithm>

Knight::Knight(int x, int y) : NPC(KnightType, x, y) {}
Knight::Knight(std::istream &is) : NPC(KnightType, is) {}

bool Knight::accept(std::shared_ptr<NPC> visitor){
    return visitor->fight(std::shared_ptr<Knight>(this,[](Knight*){}));
}

void Knight::print()
{
    std::cout << *this;
}

void Knight::save(std::ostream &os)
{
    os << KnightType << std::endl;
    NPC::save(os);
}


bool Knight::fight(std::shared_ptr<Knight> other)
{
    fight_notify(other, false);
    return true;
}

bool Knight::fight(std::shared_ptr<SlaveSaler> other)
{
    fight_notify(other, true);
    return true;
}

bool Knight::fight(std::shared_ptr<Squirrel> other)
{
    fight_notify(other, false);
    return true;
}

std::ostream &operator<<(std::ostream &os, Knight &Knight)
{
    os << "Knight: " << *static_cast<NPC *>(&Knight) << std::endl;
    return os;
}