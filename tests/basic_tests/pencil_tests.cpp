//
// Created by Caleb Smith on 11/30/2018.
//
#include "gtest/gtest.h"
#include "../../Pencil.h"

TEST(pencil_test, test_creating_pencil){
    Pencil p1 = Pencil();
    EXPECT_TRUE(&p1 != NULL);
}
TEST(pencil_test, test_that_created_pencil_has_tip_toughness){
    Pencil pl = Pencil();
    EXPECT_TRUE(pl.getTip()>0);
}
TEST(pencil_test, test_that_created_pencil_has_eraser_toughness){
    Pencil pl = Pencil();
    EXPECT_TRUE(pl.getEraser()>0);
}
