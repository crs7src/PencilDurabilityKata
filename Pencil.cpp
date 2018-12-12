//
// Created by Caleb Smith on 12/1/2018.
//
#include "Pencil.h"

Pencil::Pencil(){
    tip=100;
    eraser=100;
}

Pencil::Pencil(bool part, int toughness){
    if(part){
        eraser=toughness;
    }
    else{
        tip=toughness;
    }
}

Pencil::Pencil(int tipToughness, int eraserToughness){
    tip=tipToughness;
    eraser=eraserToughness;
}

std::string Pencil::write(std::string str, std::string paper){
    return str;
}

int Pencil::getTip() const {
    return tip;
}

int Pencil::getEraser() const {
    return eraser;
}

