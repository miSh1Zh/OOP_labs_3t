#include <gtest/gtest.h>
#include "scr/Array.h"

using dbl_point = pair<double, double>;
using int_point = pair<int, int>;

TEST(test_01, copy_and_compare_overloaded_operators_tri_double_test){
    Triangle<double> tr1(dbl_point(0, 0), dbl_point(1, 0), dbl_point(0, 1));
    Triangle<double> tr2;
    tr2 = tr1;
    ASSERT_TRUE(tr1 == tr2);
}
TEST(test_02, copy_and_compare_overloaded_operators_tri_int_test){
    Triangle<int> tr1(int_point(0, 0), int_point(1, 0), int_point(0, 1));
    Triangle<int> tr2;
    tr2 = tr1;
    ASSERT_TRUE(tr1 == tr2);
}
TEST(test_03, copy_and_compare_overloaded_operators_rect_double_test){
    Rectangle<double> rect1(dbl_point(0, 0), dbl_point(6, 0), dbl_point(6, 4), dbl_point(0, 4));
    Rectangle<double> rect2;
    rect2 = rect1;
    ASSERT_TRUE(rect1 == rect2);
}
TEST(test_04, copy_and_compare_overloaded_operators_rect_int_test){
    Rectangle<int> rect1(int_point(0, 0), int_point(6, 0), int_point(6, 4), int_point(0, 4));
    Rectangle<int> rect2;
    rect2 = rect1;
    ASSERT_TRUE(rect1 == rect2);
}
TEST(test_05, copy_and_compare_overloaded_operators_sq_double_test){
    Square<double> sq1(dbl_point(0, 0), dbl_point(4, 0), dbl_point(4, 4), dbl_point(0, 4));
    Square<double> sq2;
    sq2 = sq1;
    ASSERT_TRUE(sq1 == sq2);
}
TEST(test_06, copy_and_compare_overloaded_operators_sq_int_test){
    Square<int> sq1(int_point(0, 0), int_point(4, 0), int_point(4, 4), int_point(0, 4));
    Square<int> sq2;
    sq2 = sq1;
    ASSERT_TRUE(sq1 == sq2);
}
TEST(test_07, default_constructor_area_and_center_test){
    Triangle<int> fig;
    int_point center = fig.geom_cen();
        
    ASSERT_TRUE(center.first == 0 and center.second == 0 and round(static_cast<double>(fig)) == 0);
}
TEST(test_08, default_constructor_is_assigned_test){
    Triangle<int> fig1(int_point(0, 0), int_point(1, 0), int_point(0, 1)), fig2;
    fig1 = fig2;
        
    ASSERT_TRUE(fig1.side == 0);
}

TEST(test_09, int_sq_area_and_center_test){
    Square<int> fig(int_point(4, 4), int_point(0, 4), int_point(0, 8), int_point(4, 8));
    int_point center = fig.geom_cen();
    double area = fig;
    //check geom center
    ASSERT_TRUE(center.first == 2);
    ASSERT_TRUE(center.second == 6);
    //check area
    ASSERT_TRUE(round(area) == 16);
}
TEST(test_10, dbl_sq_area_and_center_test){
    Square<double> fig(dbl_point(4, 1), dbl_point(2, 1), dbl_point(2, -1), dbl_point(4, -1));
    int_point center = fig.geom_cen();
    double area = fig;
    //check geom center
    ASSERT_TRUE(round(center.first) == 3);
    ASSERT_TRUE(round(center.second) == 0);
    //check area
    ASSERT_TRUE(round(area) == 4);
}
TEST(test_11, int_rect_area_and_center_test){
    Rectangle<int> fig(int_point(-2, 4), int_point(6, 4), int_point(6, 6), int_point(-2, 6));
    int_point center = fig.geom_cen();
    double area = fig;
    //check geom center
    ASSERT_TRUE(center.first == 2);
    ASSERT_TRUE(center.second == 5);
    //check area
    ASSERT_TRUE(round(area) == 16);
}
TEST(test_12, dbl_rect_area_and_center_test){
    Rectangle<double> fig(dbl_point(4, 1), dbl_point(2, 1), dbl_point(2, -1), dbl_point(4, -1));
    int_point center = fig.geom_cen();
    double area = fig;
    //check geom center
    ASSERT_TRUE(round(center.first) == 3);
    ASSERT_TRUE(round(center.second) == 0);
    //check area
    ASSERT_TRUE(round(area) == 4);
}
TEST(test_13, int_tr_area_and_center_test){
    Triangle<int> fig(int_point(0, 0), int_point(0, 1), int_point(1, 0));
    int_point center = fig.geom_cen();
    double area = fig;
    //check geom center
    ASSERT_TRUE(center.first == 0);
    ASSERT_TRUE(center.second == 0);
    //check area
    ASSERT_TRUE(round(area) == 0);
}
TEST(test_14, dbl_tr_area_and_center_test){
    Triangle<double> fig(dbl_point(0, 0), dbl_point(1, 0), dbl_point(1/2, sqrt(3)/2));
    int_point center = fig.geom_cen();
    double area = fig;
    //check geom center
    ASSERT_TRUE(round(center.first) == 0);
    ASSERT_TRUE(round(center.second) == 0);
    //check area
    ASSERT_TRUE(area - sqrt(3)/4  < DBL_EPSILON);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
