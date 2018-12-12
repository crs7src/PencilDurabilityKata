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

void Pencil::sharpen() {
    tip = maxTip;
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

//reduce the durability of the pencil based on the input string
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


