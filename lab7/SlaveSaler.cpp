#include "Squirrel.hpp"
#include "Knight.hpp"
#include "SlaveSaler.hpp"
#include <algorithm>

SlaveSaler::SlaveSaler(int x, int y) : NPC(SlaveSalerType, x, y) {}
SlaveSaler::SlaveSaler(std::istream &is) : NPC(SlaveSalerType, is) {}

bool SlaveSaler::accept(std::shared_ptr<NPC> visitor){
    return visitor->fight(std::shared_ptr<SlaveSaler>(this,[](SlaveSaler*){}));
}

void SlaveSaler::print()
{
    std::cout << *this;
}

void SlaveSaler::save(std::ostream &os)
{
    os << SlaveSalerType << std::endl;
    NPC::save(os);
}


bool SlaveSaler::fight(std::shared_ptr<Knight> other)
{
    fight_notify(other, false);
    return true;
}

bool SlaveSaler::fight(std::shared_ptr<Squirrel> other)
{
    fight_notify(other, true);
    return true;
}

bool SlaveSaler::fight(std::shared_ptr<SlaveSaler> other)
{
    fight_notify(other, false);
    return true;
}

std::ostream &operator<<(std::ostream &os, SlaveSaler &SlaveSaler)
{
    os << "SlaveSaler: " << *static_cast<NPC *>(&SlaveSaler) << std::endl;
    return os;
}