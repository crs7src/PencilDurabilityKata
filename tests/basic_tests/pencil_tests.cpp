//
// Created by Caleb Smith on 11/30/2018.
//
#include "gtest/gtest.h"
#include "../../Pencil.h"

class pencil_test : public ::testing::Test{
protected:
    Pencil p1;
    Pencil p2 = Pencil(200, 200, 200);
};
TEST_F(pencil_test, test_creating_pencil){
    Pencil pencil = Pencil();
    EXPECT_TRUE(&pencil != NULL);
}
TEST_F(pencil_test, test_that_created_pencil_has_tip_toughness){
    Pencil pencil = Pencil();
    EXPECT_TRUE(pencil.getTip()>0);
}
TEST_F(pencil_test, test_creating_pencil_with_set_tip_eraser_and_length){
    EXPECT_EQ(p2.getEraser(),200);
    EXPECT_EQ(p2.getTip(),200);
    EXPECT_EQ(p2.getLength(),200);
}
TEST_F(pencil_test, test_sharpening_pencil){
    std::string paper = "";
    std::string text = "test";
    std::string text2 = " sharpening";
    //tip should degrade on characters
    paper = p1.write(text, paper);
    paper = p2.write(text2, paper);
    EXPECT_EQ(p1.getTip(), 96);
    EXPECT_EQ(p2.getTip(), 190);
    p1.sharpen();
    p2.sharpen();
    EXPECT_EQ(p1.getTip(), 100);
    EXPECT_EQ(p2.getTip(), 200);
}
TEST_F(pencil_test, test_creating_pencil_with_set_length){
    //tip should degrade on characters
    Pencil pencil = Pencil(200, 200, 200);
    Pencil pencil2 = Pencil();
    EXPECT_EQ(pencil.getLength(), 200);
    EXPECT_TRUE(pencil2.getTip()>0);
}
TEST_F(pencil_test, test_sharpening_pencil_reduces_length){
    std::string paper = "";
    std::string text = "test";
    std::string text2 = " sharpening";
    //tip should degrade on characters
    paper = p1.write(text, paper);
    paper = p2.write(text2, paper);
    EXPECT_EQ(p1.getLength(), 100);
    EXPECT_EQ(p2.getLength(), 200);
    p1.sharpen();
    p2.sharpen();
    EXPECT_EQ(p1.getLength(), 99);
    EXPECT_EQ(p2.getLength(), 199);
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
    EXPECT_EQ(paper, "test    ");
}
TEST(write_test, test_pencil_should_lose_2_tip_toughness_from_capital_letters){
    Pencil p1 = Pencil();
    std::string paper = "";
    std::string text = "T";
    std::string text2 = "TEST";
    paper = p1.write(text, paper);
    EXPECT_EQ(98, p1.getTip());
    paper = p1.write(text2, paper);
    EXPECT_EQ(90, p1.getTip());
}
