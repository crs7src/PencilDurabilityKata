//
// Created by Caleb Smith on 12/1/2018.
//
#include "Pencil.h"

//create pencil with nothing specified
Pencil::Pencil(){
    tip=100;
    eraser=100;
}
//create pencil with either point or eraser toughness specified(part=0, tip|part=1, eraser)
Pencil::Pencil(bool part, int toughness){
    if(part){
        eraser=toughness;
        tip = 100;
    }
    else{
        tip=toughness;
        eraser = 100;
    }
}
//create pencil with specified toughnesses
Pencil::Pencil(int tipToughness, int eraserToughness){
    tip=tipToughness;
    eraser=eraserToughness;
}
//write a string onto the paper
//append the string onto the paper and degrade the pencil
std::string Pencil::write(std::string str, std::string paper){
    pointDegradation(str);
    return paper.append(str);
}

int Pencil::getTip() const {
    return tip;
}

int Pencil::getEraser() const {
    return eraser;
}
//reduce the durability of the pencil based on the input string
//remove one from "tip" for every non-whitespace character
void Pencil::pointDegradation(std::string str){
    int whitespace = 0;
    for (int i = 0; i < str.length(); ++i) {
        if(std::isspace(str.at(i))){
            whitespace++;
        }
    }
    tip-=(str.length()-whitespace);
}
