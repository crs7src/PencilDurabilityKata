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
TEST_F(pencil_test, test_sharpening_pencil_cannot_reduce_length_below_zero){
    Pencil pencil = Pencil(100, 100, 1);
    std::string paper = "";
    std::string text = "test";
    paper = pencil.write(text, paper);
    pencil.sharpen();
    paper = pencil.write(text, paper);
    EXPECT_EQ(pencil.getLength(), 0);
    pencil.sharpen();
    EXPECT_EQ(pencil.getLength(), 0);
}
TEST_F(pencil_test, test_sharpening_when_when_length_is_zero_does_not_reset_tip){
    Pencil pencil = Pencil(100, 100, 1);
    std::string paper = "";
    std::string text = "test";
    paper = pencil.write(text, paper);
    pencil.sharpen();
    paper = pencil.write(text, paper);
    EXPECT_EQ(pencil.getTip(), 96);
    pencil.sharpen();
    EXPECT_EQ(pencil.getTip(), 96);
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

class edit_test : public ::testing::Test{
protected:
    Pencil p1;
};

TEST_F(edit_test, test_erasing_last_instance_of_a_word){
    std::string paper = p1.erase("chuck", "How much wood would a woodchuck chuck if a woodchuck could chuck wood?");
    EXPECT_EQ(paper, "How much wood would a woodchuck chuck if a woodchuck could       wood?");
    paper = p1.erase("chuck", paper);
    EXPECT_EQ(paper, "How much wood would a woodchuck chuck if a wood      could       wood?");
}
TEST_F(edit_test, test_erasing_word_that_isnt_on_paper){
    std::string paper = p1.erase("the", "How much wood would a woodchuck chuck if a woodchuck could chuck wood?");
    EXPECT_EQ(paper, "How much wood would a woodchuck chuck if a woodchuck could chuck wood?");
}
TEST_F(edit_test, test_erasing_word_should_reduce_eraser_toughness){
    int eraserStart = p1.getEraser();
    std::string paper = p1.erase("c", "How much wood would a woodchuck chuck if a woodchuck could chuck wood?");
    EXPECT_EQ(eraserStart-1, p1.getEraser());
    eraserStart = p1.getEraser();
    p1.erase("chuck", "How much wood would a woodchuck chuck if a woodchuck could chuck wood?");
    EXPECT_EQ(eraserStart-5, p1.getEraser());
}
TEST_F(edit_test, test_erasing_space_should_not_reduce_eraser_toughness){
    int eraserStart = p1.getEraser();
    std::string paper = p1.erase("chuck if", "How much wood would a woodchuck chuck if a woodchuck could chuck wood?");
    EXPECT_EQ(paper, "How much wood would a woodchuck          a woodchuck could chuck wood?");
    EXPECT_EQ(eraserStart-7, p1.getEraser());
}
TEST_F(edit_test, test_erasing_at_zero_eraser_toughness_should_do_nothing){
    Pencil pencil = Pencil(100, 0, 100);
    std::string paper = pencil.erase("Bill", "Buffalo Bill");
    EXPECT_EQ(paper, "Buffalo Bill");
}
TEST_F(edit_test, test_erasing_should_go_right_to_left_and_stop_when_eraser_hits_zero){
    Pencil pencil = Pencil(100, 3, 100);
    std::string paper = pencil.erase("Bill", "Buffalo Bill");
    EXPECT_EQ(paper, "Buffalo B   ");
}
TEST_F(edit_test, test_erasing_apple_and_replacing_with_onion){
    std::string paper = p1.erase("apple", "an apple a day keeps the doctor away");
    EXPECT_EQ(paper, "an       a day keeps the doctor away");
    paper = p1.edit("onion", paper);
    EXPECT_EQ(paper, "an onion a day keeps the doctor away");
}
TEST_F(edit_test, test_editing_in_words_reduces_tip_toughness){
    std::string paper = p1.erase("apple", "an apple a day keeps the doctor away");
    int startingToughness = p1.getTip();
    paper = p1.edit("onion", paper);
    EXPECT_EQ(p1.getTip(), startingToughness-5);
    paper = p1.erase("day", "an apple a day keeps the doctor away");
    startingToughness = p1.getTip();
    paper = p1.edit("year", paper);
    EXPECT_EQ(p1.getTip(), startingToughness-4);
}
TEST_F(edit_test, test_editing_in_words_doesnt_work_if_tip_is_dull){
    Pencil pencil = Pencil(4);
    std::string paper = pencil.erase("apple", "an apple a day keeps the doctor away");
    paper = pencil.edit("onion", paper);
    EXPECT_EQ(pencil.getTip(), 0);
    EXPECT_EQ(paper, "an onio  a day keeps the doctor away");
    paper = pencil.erase("day", paper);
    paper = pencil.edit("year", paper);
    EXPECT_EQ(pencil.getTip(), 0);
    EXPECT_EQ(paper, "an onio  a     keeps the doctor away");
}
TEST_F(edit_test, test_editing_in_words_should_do_nothing_if_there_is_no_empty_space){
    Pencil pencil = Pencil(4);
    std::string paper ="an apple a day keeps the doctor away";
    paper = pencil.edit("onion", paper);
    EXPECT_EQ(paper, "an apple a day keeps the doctor away");
}
//TODO: create tests for:
//degrading tip
//overwriting characters
//if there is no blank space