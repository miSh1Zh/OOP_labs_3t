#include <gtest/gtest.h>
#include "src/eleven.h" 


TEST(test_01, basic_test_set){
    bool checked = false; //проверка на корректность вычитания (из меньшего нельзя вычесть большее)
    try{
        
        Eleven bf_great {"10232131aa327"};
        Eleven bf_small {"7"};

        bf_small.deduct(bf_great);

    }catch(exception &ex){
        checked = true;
    }

    ASSERT_TRUE(checked);
}

TEST(test_02, basic_test_set){
    Eleven bf_great {"12aa7"}; //проверка на вычитание нуля
    Eleven bf_small {"0"};

    Eleven bf_copy {bf_great};

    bf_great.deduct(bf_small);

    ASSERT_TRUE(bf_great.equal(bf_copy));
}

TEST(test_03, basic_test_set){
    bool checked = false;
    try{
        
        Eleven bf_null {""};

    }catch(exception &ex){ //no number was given
        checked = true;
    }

    ASSERT_TRUE(checked);
}

TEST(test_04, basic_test_set){
    Eleven bf_great {"10243aa325"};
    Eleven bf_small {"0000000aaa"};
    
    ASSERT_TRUE(bf_great.greater(bf_small));
}

TEST(test_05, basic_test_set){
    bool checked = false;//check exception of non-11-decimal numbers
    try{
        Eleven not_11dec {"177qwertyabab"};
    }
    catch(exception &ex){
        checked = true;
    }

    ASSERT_TRUE(checked);
}

TEST(test_06, basic_test_set){  //простая проверка сложения
    Eleven bf_great {"1024"}; 
    Eleven bf_small {"12"};
    bf_great.add(bf_small);
    ASSERT_TRUE(bf_great.equal(Eleven{"1036"}));
}

TEST(test_07, basic_test_set){ // complex constructor test
    Eleven bf_one(4, '5');
    Eleven bf_two{'5', '5'};
    Eleven bf_tree{"05500"};
    ASSERT_TRUE((bf_two.add(bf_tree)).equal(bf_one));
}

TEST(test_08, basic_test_set){ // ZERO COMPLEX test
    ASSERT_TRUE(!(Eleven(3, '0').add(Eleven{'0'}).deduct(Eleven{"0000000000"})).less(Eleven(1, '0')));
}

TEST(test_09, basic_test_set){ // "result._size is more then max_size" test
    ASSERT_TRUE((Eleven{"aa"}.add(Eleven{"1"})).equal(Eleven{"100"}));    
}

TEST(test_10, basic_test_set){ // Grand finality by testing long arithmetic (checked on paper!)
    ASSERT_TRUE(Eleven{"1000000000011001111000000aa"}.add(Eleven{"2"}).deduct(Eleven{"a1000000000000000"}).equal(Eleven{"aaaaaaaaa10100111100000101"}));    
}

TEST(test_11, basic_test_set){
    Eleven bf {"121a"};
    ASSERT_TRUE(bf.add(Eleven()).equal(bf));
}

TEST(test_12, basic_test_set){
    Eleven bf1 {"121a"};
    Eleven bf2 {"121a"};
    ASSERT_TRUE(bf1.add(Eleven()).equal(bf2));
}

TEST(test_13, basic_test_set){
    Eleven bf {"121a"};
    ASSERT_TRUE(bf.greater(Eleven()));
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
