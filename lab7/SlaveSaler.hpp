#pragma once
#include "npc.hpp"

struct SlaveSaler : public NPC
{
    SlaveSaler(int x, int y);
    SlaveSaler(std::istream &is);

    void print() override;

    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<Squirrel> other) override;
    bool fight(std::shared_ptr<SlaveSaler> other) override;
    bool accept(std::shared_ptr<NPC> visitor) override;
    

    void save(std::ostream &os) override;

    friend std::ostream &operator<<(std::ostream &os, SlaveSaler &dragon);
};