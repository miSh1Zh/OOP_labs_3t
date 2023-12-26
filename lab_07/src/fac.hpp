#pragma once

#include "npc.hpp"
#include "dragon.hpp"
#include "elf.hpp"
#include "druid.hpp"
#include "observer.hpp"

// template<class T>


std::shared_ptr<NPC> factory(std::istream &is);

std::shared_ptr<NPC> factory(NpcType type, int x, int y);