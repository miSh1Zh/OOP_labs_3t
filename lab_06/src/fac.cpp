#include "fac.hpp"


std::shared_ptr<NPC> factory(std::istream &is)
{
    std::shared_ptr<NPC> result;
    int type{0};
    if (is >> type)
    {
        switch (type)
        {
        case DragonType:
            result = std::make_shared<Dragon>(is);
            break;
        case DruidType:
            result = std::make_shared<Druid>(is);
            break;
        case ElfType:
            result = std::make_shared<Elf>(is);
            break;
        }
    }
    else
        std::cerr << "unexpected NPC type:" << type << std::endl;

    if (result)
        result->subscribe(TextObserver::get());

    return result;
}

std::shared_ptr<NPC> factory(NpcType type, int x, int y)
{
    std::shared_ptr<NPC> result;
    switch (type)
    {
    case DragonType:
        result = std::make_shared<Dragon>(x, y);
        break;
    case ElfType:
        result = std::make_shared<Elf>(x, y);
        break;
    case DruidType:
        result = std::make_shared<Druid>(x, y);
        break;
    default:
        break;
    }
    if (result)
        result->subscribe(TextObserver::get());

    return result;
}