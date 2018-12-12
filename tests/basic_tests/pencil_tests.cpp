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
TEST(write_test, test_writing_to_paper){
    Pencil p1 = Pencil();
    Pencil p2 = Pencil();
    std::string paper = "";
    std::string text = "test";
    std::string paper2 = "";
    std::string text2 = "test2";
    paper = p1.write(text, paper);
    paper2 = p2.write(text2, paper2);
    EXPECT_EQ(paper, text);
    EXPECT_EQ(paper2, text2);
}
TEST(write_test, test_adding_to_paper_that_isnt_blank){
    Pencil p1 = Pencil();
    std::string paper = "test";
    std::string text = " number 3";
    paper = p1.write(text, paper);
    EXPECT_EQ(paper, "test number 3");
}
TEST(write_test, test_point_degredation_on_writing) {
    Pencil p1 = Pencil();
    std::string paper = "";
    std::string text = "test";
    std::string text2 = " degradation";
    //tip should degrade on characters
    paper = p1.write(text, paper);
    EXPECT_EQ(p1.getTip(), 96);
    //tip should not degrade on whitespace
    paper = p1.write(text2, paper);
    EXPECT_EQ(p1.getTip(), 85);
}
TEST(write_test, test_pencil_should_not_write_if_toughness_is_0){
    bool part = 0;
    Pencil p1 = Pencil(part, 4);
    std::string paper = "";
    std::string text = "test";
    paper = p1.write(text, paper);
    EXPECT_EQ(paper, text);
    paper = p1.write(text, paper);
    EXPECT_EQ(paper, text);
}