#include <gtest/gtest.h>
#include <iostream>
#include "include/allocator.h"
#include "include/2w_list.h"

#define BLOCKS 1024

TEST(ListAllocator, test1) {

    List<int, My_Allocator::Allocator<int> > lst;
    lst.emplace_back(10);
    ASSERT_TRUE(*lst.begin() == 10);
}


TEST(ListAllocator, test2) {

    List<double, My_Allocator::Allocator<double> > lst;
    EXPECT_ANY_THROW(lst.erase(lst.begin()));
}

TEST(ListAllocator, test3){
    List<int, My_Allocator::Allocator<int>> lst;

    lst.emplace_back(10);
    lst.emplace_back(10);
    lst.emplace_back(10);
    lst.emplace_back(10);
    lst.emplace(++lst.begin(), 77);
    lst.emplace_front(15);

    List<int, My_Allocator::Allocator<int>>::Iterator tmp1, tmp2;
    
    for(List<int, My_Allocator::Allocator<int>>::Iterator it = lst.begin(); it != lst.end(); ++it){
        if(*it == 77) tmp1 = it;
        if(*it == 10) tmp2 = it;
    }

    ASSERT_TRUE(*lst.begin() == 15);
    ASSERT_TRUE(*tmp1 == 77);
    ASSERT_TRUE(*tmp2 == 10);
    
    ASSERT_TRUE(lst.size() == 6);
}



auto main(int argc, char** argv) -> int {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
