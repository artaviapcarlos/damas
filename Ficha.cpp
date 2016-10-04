//
// Created by artv23 on 30/09/16.
//

#include "Ficha.h"

Ficha::Ficha(int color, int num) : color(color), corona(false), num(num) { }

int Ficha::getColor() const {
    return color;
}

void Ficha::coronar() {
    corona = true;
}

int Ficha::getNum() {
    return num;
}

void Ficha::setNum(int num) {
    this->num = num;
}

string Ficha::toString() {
    stringstream s;

    if(color)
        s << "N" << num;
    else
        s << "B" << num;

    if(corona)
        s << " (c)";

    return s.str();
}