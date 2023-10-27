#include <gtest/gtest.h>
#include "scr/Array.h"

TEST(test_01, copy_and_compare_overloaded_operators_tri_test){

    Point pt1(0, 0); 
    Point pt2(1, 1); 
    Point pt3(0, 1);
    
    Triangle tr1(pt1, pt2, pt3);

    Triangle tr2;
    tr2 = tr1;

    ASSERT_TRUE(tr1 == tr2);
}

TEST(test_02, copy_and_compare_overloaded_operators_sq_test){

    Point pt1(0, 0); 
    Point pt2(1, 1); 
    Point pt3(0, 1);
    Point pt4(1, 0);
    
    Square fig1(pt1, pt2, pt3, pt4);

    Square fig2;
    fig2 = fig1;

    ASSERT_TRUE(fig1 == fig2);
}

TEST(test_03, copy_and_compare_overloaded_operators_rect_test){

    Point pt1(0, 0); 
    Point pt2(4, 6); 
    Point pt3(0, 6);
    Point pt4(4, 0);
    
    Rectangle fig1(pt1, pt2, pt3, pt4);

    Rectangle fig2;
    fig2 = fig1;

    ASSERT_TRUE(fig1 == fig2);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
