//
// Created by Caleb Smith on 12/1/2018.
//
#include "Pencil.h"

Pencil::Pencil(){}

Pencil::Pencil(bool part, int toughness){
    if(part){
        eraser=toughness;
    }
    else{
        tip=toughness;
    }
}

int Pencil::getTip() const {
    return tip;
}

int Pencil::getEraser() const {
    return eraser;
}

