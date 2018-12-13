//
// Created by Caleb Smith on 12/1/2018.
//
#include <afxres.h>
#include "Pencil.h"

//create pencil with specified toughnesses and length
Pencil::Pencil(int tipToughness, int eraserToughness, int pencilLength){
    tip = maxTip = tipToughness;
    eraser = eraserToughness;
    length = pencilLength;
}
//write a string onto the paper
//append the string onto the paper and degrade the pencil
std::string Pencil::write(std::string str, std::string paper){
    pointDegradation(str);
    if(tip < 0){
        paper.append(str, 0, str.length()+tip);
        paper.append(-tip, ' ');
        tip = 0;
        return paper;
    }
    return paper.append(str);
}
//sets the tip toughness back to the state it was at when the pencil was created
//reduces the length of the pencil by one
void Pencil::sharpen() {
    if(length) {
        length--;
        tip = maxTip;
    }
}

//erases the last instance of the input str on the paper
//it erases right to left and if the eraser hits zero then it stops
std::string Pencil::erase(std::string str, std::string paper){
    std::size_t last_instance = paper.rfind(str);
    if(last_instance!=std::string::npos) {
        eraserDegradation(str);
        if(eraser > 0) {
            paper.replace(last_instance, str.length(), std::string(str.length(), ' '));
        }
        else {
            paper.replace(last_instance - eraser, str.length() + eraser, std::string(str.length() + eraser, ' '));
            eraser = 0;
        }
    }
    return paper;
}
//writes new text in an empty segment of text
//overlaps in text should be @ symbols
std::string Pencil::edit(std::string str, std::string paper){
    std::size_t empty_space = paper.find("   ");
    if(empty_space!=std::string::npos) {
        pointDegradation(str);
        if (tip < 0) {
            str.erase(str.length() + tip, str.length());
            paper.replace(empty_space + 1, str.length(), str);
            tip = 0;
            return paper;
        }
        paper.replace(empty_space + 1, str.length(), str);
    }
    return paper;
}

int Pencil::getTip() const {
    return tip;
}

int Pencil::getLength() const {
    return length;
}

int Pencil::getEraser() const {
    return eraser;
}

//reduce the durability of the pencil tip based on the input string
//remove one from "tip" for every non-whitespace character
//remove two from "tip" for every capital letter
void Pencil::pointDegradation(std::string str){
    int whitespace = 0;
    int caps = 0;
    for (int i = 0; i < str.length(); ++i) {
        if(std::isspace(str.at(i))){
            whitespace++;
        }
        if(std::isupper(str.at(i))){
            caps++;
        }
    }
    tip-=(str.length()-whitespace+caps);
}

//reduce the durability of the pencil eraser based on the input string
//remove one from "eraser" for every non-whitespace character
void Pencil::eraserDegradation(std::string str){
    int whitespace = 0;
    for (int i = 0; i < str.length(); ++i) {
        if(std::isspace(str.at(i))){
            whitespace++;
        }
    }
    eraser-=(str.length()-whitespace);
}


