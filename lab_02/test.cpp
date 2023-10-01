#include <gtest/gtest.h>
#include "src/eleven.h" 


TEST(test_01, basic_test_set){
    bool checked = false;
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
    Eleven bf_great {"12aa7"};
    Eleven bf_small {"0"};

    Eleven bf_copy {bf_great};

    bf_great.deduct(bf_small);

    ASSERT_TRUE(bf_great.equal(bf_copy));
}

TEST(test_03, basic_test_set){
    bool checked = false;
    try{
        
        Eleven bf_null {""};

    }catch(exception &ex){
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

TEST(test_06, basic_test_set){
    Eleven bf_great {"1024"};
    Eleven bf_small {"12"};
    bf_great.add(bf_small);
    ASSERT_TRUE(bf_great.equal(Eleven{"1036"}));
}


int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
