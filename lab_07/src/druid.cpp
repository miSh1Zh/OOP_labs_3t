#include "dragon.hpp"
#include "elf.hpp"
#include "druid.hpp"

Druid::Druid(int x, int y) : NPC(DruidType, x, y) {}
Druid::Druid(std::istream &is) : NPC(DruidType, is) {}

void Druid::print()
{
    std::cout << *this;
}


bool Druid::accept(std::shared_ptr<NPC> visitor){
    return visitor->fight(std::shared_ptr<Druid>(this,[](Druid*){}));
}

bool Druid::fight(std::shared_ptr<Dragon> other) 
{
    fight_notify(other, true);
    return true;
}

bool Druid::fight(std::shared_ptr<Druid> other) 
{
    fight_notify(other, false);
    return false;
}

bool Druid::fight(std::shared_ptr<Elf> other) 
{
    fight_notify(other, false);
    return false;
}

void Druid::save(std::ostream &os) 
{
    os << DruidType << std::endl;
    NPC::save(os);
}

std::ostream &operator<<(std::ostream &os, Druid &druid)
{
    os << "druid: " << *static_cast<NPC *>(&druid) << std::endl;
    return os;
}
