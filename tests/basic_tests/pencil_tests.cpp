//
// Created by Caleb Smith on 11/30/2018.
//
#include "gtest/gtest.h"

TEST(basic_check, test_eq){
    EXPECT_EQ(1,0);
}

TEST(basic_check, testnq) {
    EXPECT_NE(1,0);
}
