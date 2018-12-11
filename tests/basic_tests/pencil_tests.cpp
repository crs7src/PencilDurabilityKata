//
// Created by Caleb Smith on 11/30/2018.
//
#include "gtest/gtest.h"
#include "../../Pencil.h"
#include <stdio.h>

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
TEST(pencil_test, test_creating_pencil_with_set_tip){
    int tip = 5000;
    bool part = 0;
    Pencil pl = Pencil(part, tip);
    EXPECT_TRUE(pl.getTip()==tip);
}
TEST(pencil_test, test_creating_pencil_with_set_eraser) {
    int eraser = 10000;
    bool part = 1;
    Pencil pl = Pencil(part, eraser);
    EXPECT_TRUE(pl.getEraser() == eraser);
}
TEST(pencil_test, test_creating_pencil_with_set_tip_and_eraser){
    int eraser = 10000;
    int tip = 5000;
    Pencil pl = Pencil(tip, eraser);
    EXPECT_TRUE(pl.getEraser()==eraser);
    EXPECT_TRUE(pl.getTip()==tip);
}