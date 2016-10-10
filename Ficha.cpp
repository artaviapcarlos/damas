//
// Created by artv23 on 30/09/16.
//

#include "Ficha.h"

Ficha::Ficha(int color) : color(color), corona(false){
    resetColorOpos();
}

int Ficha::getColor() const {
    return color;
}

void Ficha::setColor(int color) {
    this->color = color;
    resetColorOpos();
}

int Ficha::getColorOpos() const {
    return colorOpos;
}

void Ficha::resetColorOpos(){
    switch(color){
        case 0:
            colorOpos = 1;
            break;

        case 1:
            colorOpos = 0;
            break;

        default:
            colorOpos = 2;
            break;
    }
}

bool Ficha::getCorona() const {
    return corona;
}

void Ficha::setCorona(bool corona) {
    this->corona = corona;
}

void Ficha::coronar() {
    corona = true;
}

string Ficha::toString() {
    stringstream s;

    if(color == 2)
        s << "X";
    if(color == 1)
        s << "N";
    if(color == 0)
        s << "B";

    if(corona)
        s << " (c)";

    return s.str();
}