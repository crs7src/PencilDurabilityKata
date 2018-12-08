//
// Created by Caleb Smith on 11/30/2018.
//
#include "gtest/gtest.h"
#include "../../Pencil.h"

TEST(pencil_test, test_creating_pencil){
    Pencil p1 = new Pencil();
    EXPECT_TRUE(&p1 != NULL);
}

