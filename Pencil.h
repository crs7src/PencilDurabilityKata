//
// Created by Caleb Smith on 12/1/2018.
//
#include"string"
#include "stdio.h"

#ifndef PENCILDURABILITYKATA_PENCIL_H
#define PENCILDURABILITYKATA_PENCIL_H

class Pencil {

public:
    //create pencil with specific toughnesses and length
    Pencil(int pointToughness = 100, int eraserToughness = 100, int pencilLength = 100);
    //write the first string onto the end of the second string
    std::string write(std::string str, std::string paper);
    //sharpen the pencil to refresh the point toughness
    void sharpen();
    //erase the rightmost instance of the input str from the paper
    std::string erase(std::string str, std::string paper);
    //if an erase was made then add the str where the erase happened
    std::string edit(std::string str, std::string paper);

    int getTip() const;

    int getLength() const;

    int getEraser() const;

private:
    //damage the tip of the pencil based on the amount written
    void pointDegradation(std::string str);
    //damage the eraser of the pencil based on the amount erased
    void eraserDegradation(std::string str);
    int tip;
    int maxTip;
    int eraser;
    int length;
};


#endif //PENCILDURABILITYKATA_PENCIL_H
