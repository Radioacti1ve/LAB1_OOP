#pragma once
#include "npc.hpp"

struct Squirrel : public NPC
{
    Squirrel(int x, int y);
    Squirrel(std::istream &is);

    void print() override;

    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<Squirrel> other) override;
    bool fight(std::shared_ptr<SlaveSaler> other) override;
    bool accept(std::shared_ptr<NPC> visitor) override;
    

    void save(std::ostream &os) override;

    friend std::ostream &operator<<(std::ostream &os, Squirrel &dragon);
};