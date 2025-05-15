#include <gtest/gtest.h>
#include "customString.h"


TEST(customString, appendCharacters){
    customString str;
    str.append('h');
    str.append('i');
    EXPECT_STREQ(str.getString(), "hi");
}
TEST(customString, initialize){
    char arr[5] = {'w','o','r', 'l', 'd'};
    customString world(arr, 5);
    EXPECT_STREQ(world.getString(), "world");
}

TEST(customString, indexOperator){
    char arr[5] = {'w','o','r', 'l', 'd'};
    customString world(arr, 5);
    EXPECT_EQ(world[2], 'r');

}
TEST(customString, concatenate){
    customString hi;
    hi.append('h');
    hi.append('i');

    char arr[5] = {'w','o','r', 'l', 'd'};
    customString world(arr, 5);

    hi.concatenate(world.getString());
    EXPECT_STREQ(hi.getString(), "hiworld");

}

TEST(customString, remove){
    char arr[5] = {'w','o','r', 'l', 'd'};
    
    customString world(arr, 5);
    world.remove(2, 2);
    EXPECT_STREQ(world.getString(), "wod");

    customString world1(arr, 5);
    world1.remove(-1, 2);
    EXPECT_STREQ(world1.getString(), "world");



}

TEST(customString, removeTooMuch){
    char arr[5] = {'w','o','r', 'l', 'd'};

    customString world2(arr, 5);
    world2.remove(3, 4);
    EXPECT_STREQ(world2.getString(), "wor");
}

