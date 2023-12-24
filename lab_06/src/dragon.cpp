#include "dragon.hpp"
#include "elf.hpp"
#include "druid.hpp"

Dragon::Dragon(int x, int y) : NPC(DragonType, x, y) {}
Dragon::Dragon(std::istream &is) : NPC(DragonType, is) {}

void Dragon::print()
{
    std::cout << *this;
}

// bool Dragon::is_dragon() const 
// {
//     return true;
// }

bool Dragon::accept(std::shared_ptr<NPC> attacker) {
    std::shared_ptr<Dragon> This = std::make_shared<Dragon>(*this);
    return attacker->visit(This);
}

bool Dragon::fight(std::shared_ptr<Dragon> other) 
{
    fight_notify(other, false);
    return false;
}

bool Dragon::fight(std::shared_ptr<Druid> other) 
{
    fight_notify(other, false);
    return false;
}

bool Dragon::fight(std::shared_ptr<Elf> other) 
{
    fight_notify(other, true);
    return true;
}

void Dragon::save(std::ostream &os) 
{
    os << DragonType << std::endl;
    NPC::save(os);
}

std::ostream &operator<<(std::ostream &os, Dragon &dragon)
{
    os << "dragon: " << *static_cast<NPC *>(&dragon) << std::endl;
    return os;
}
