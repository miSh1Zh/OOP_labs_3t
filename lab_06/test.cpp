#include <gtest/gtest.h>
#include "src/npc.hpp"
#include "src/dragon.hpp"
#include "src/elf.hpp"
#include "src/druid.hpp"
#include "src/observer.hpp"

TEST(NPCInteractions, test1) {
    std::shared_ptr<NPC> first = std::make_shared<Dragon>(0, 0);
    std::shared_ptr<NPC> second = std::make_shared<Elf>(1, 1);

    bool murder = second->accept(first);
    ASSERT_TRUE(murder);
}

TEST(NPCInteractions, test2) {
    std::shared_ptr<NPC> first = std::make_shared<Dragon>(0, 0);
    std::shared_ptr<NPC> second = std::make_shared<Druid>(1, 1);

    bool murder = second->accept(first);
    ASSERT_FALSE(murder);
}

TEST(NPCInteractions, test3) {
    std::shared_ptr<NPC> first = std::make_shared<Dragon>(0, 0);
    std::shared_ptr<NPC> other_first = std::make_shared<Dragon>(1, 1);

    bool murder = first->accept(other_first);
    ASSERT_FALSE(murder);
}

TEST(NPCInteractions, test4) {
    std::shared_ptr<NPC> first = std::make_shared<Druid>(0, 0);
    std::shared_ptr<NPC> second = std::make_shared<Elf>(1, 1);

    bool murder = second->accept(first);
    ASSERT_FALSE(murder);
}

TEST(NPCInteractions, test5) {
    std::shared_ptr<NPC> first = std::make_shared<Druid>(0, 0);
    std::shared_ptr<NPC> second = std::make_shared<Druid>(1, 1);

    bool murder = second->accept(first);
    ASSERT_FALSE(murder);
}

TEST(NPCInteractions, test6) {
    std::shared_ptr<NPC> first = std::make_shared<Druid>(0, 0);
    std::shared_ptr<NPC> second = std::make_shared<Dragon>(1, 1);

    bool murder = second->accept(first);
    ASSERT_TRUE(murder);
}

TEST(NPCInteractions, test7) {
    std::shared_ptr<NPC> first = std::make_shared<Elf>(0, 0);
    std::shared_ptr<NPC> second = std::make_shared<Elf>(1, 1);

    bool murder = second->accept(first);
    ASSERT_FALSE(murder);
}

TEST(NPCInteractions, test8) {
    std::shared_ptr<NPC> first = std::make_shared<Elf>(0, 0);
    std::shared_ptr<NPC> second = std::make_shared<Druid>(1, 1);

    bool murder = second->accept(first);
    ASSERT_TRUE(murder);
}

TEST(NPCInteractions, test9) {
    std::shared_ptr<NPC> first = std::make_shared<Elf>(0, 0);
    std::shared_ptr<NPC> second = std::make_shared<Dragon>(1, 1);

    bool murder = second->accept(first);
    ASSERT_FALSE(murder);
}


int main(int argc, char** argv){

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}