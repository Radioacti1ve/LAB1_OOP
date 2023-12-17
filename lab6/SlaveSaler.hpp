#pragma once
#include "npc.hpp"

class SlaveSaler : public NPC{
    public:
        SlaveSaler(const int&, const int&, const std::string&);

        void print(std::ostream&) override;

        void accept(NPC*, const int&) override;

        friend std::ostream& operator<<(std::ostream&, const SlaveSaler&);

};