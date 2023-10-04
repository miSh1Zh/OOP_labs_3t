#include <gtest/gtest.h>
#include "src/function.h" 


TEST(test_01, basic_test_set){
    ASSERT_TRUE(trace_string("a") == ""); // проверка на отсутствие ложного срабатывания
}

TEST(test_02, basic_test_set){
    ASSERT_TRUE(trace_string("243") == "243\n"); //проверка на случай отсутствия букв
}

TEST(test_03, basic_test_set){
    ASSERT_TRUE(trace_string("a1012bfsc12") == "1012\n12\n"); //проверка считывания числа, которое стоит в самом конце строки (после неё нет буквы для сброса на след стадии цикла)
}

TEST(test_04, basic_test_set){
    ASSERT_TRUE(trace_string("203цук04") == "203\n0\n4\n"); //проверка на нуль
}

TEST(test_05, basic_test_set){
    ASSERT_TRUE(trace_string("") == ""); // проверка на пустой тест
}


int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
