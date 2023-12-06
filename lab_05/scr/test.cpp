#include <gtest/gtest.h>
#include <iostream>
#include "include/allocator.h"
#include "include/2w_list.h"

#define BLOCKS 1024

TEST(AllocTests, test1) {

    std::map<double, double, std::less<int>, My_Allocator::Allocator<std::pair<const double, double> > > test_map;
    test_map[1] = 1;
    test_map[2] = 3;
    test_map[3] = 5;
    test_map[4] = 6;
    test_map[5] = 8;

    testing::internal::CaptureStdout(); 
    for(const auto& [k,v]: test_map) {
            std::cout << k << " " << v << std::endl;
    } 
    std::string output = testing::internal::GetCapturedStdout(); 

    testing::internal::CaptureStdout();
    std::cout << 1 << " " << 1 << std::endl;
    std::cout << 2 << " " << 3 << std::endl;
    std::cout << 3 << " " << 5 << std::endl;
    std::cout << 4 << " " << 6 << std::endl;
    std::cout << 5 << " " << 8 << std::endl;
    std::string ans = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, ans);
}

TEST(ListAllocator, test2) {

    List<int, My_Allocator::Allocator<int> > lst;
    lst.emplace_back(10);
    ASSERT_TRUE(lst.end() == 10);
}

TEST(ListAllocator, test3) {

    List<int, My_Allocator::Allocator<int> > lst;
    lst.emplace_back(1);
    lst.emplace_back(5);
    lst.erase(lst.end());

    ASSERT_TRUE(lst.begin() == 5);   
}

TEST(ListAllocator, test4) {

    List<int, My_Allocator::Allocator<int> > lst;
    lst.emplace_back(1);
    lst.emplace_back(5);
    lst.erase(lst.end());
    lst.emplace_back(1);

    ASSERT_TRUE(lst.end() == 5);   
}



TEST(ListAllocator, test5) {

    List<int, My_Allocator::Allocator<int> > lst;
    lst.emplace_back(1);
    lst.emplace_back(5);
    lst.erase(lst.begin());
    lst.erase(lst.begin());
    lst.emplace_back(1);

    ASSERT_TRUE(lst.begin() == 1);   
}

TEST(ListAllocator, test6) {

    List<int, My_Allocator::Allocator<int> > lst;
    ASSERT_TRUE(lst.begin() == lst.end());
}

TEST(ListAllocator, test7) {

    List<double, My_Allocator::Allocator<double> > lst;
    EXPECT_ANY_THROW(lst.erase(lst.begin()));
}



auto main(int argc, char** argv) -> int {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
