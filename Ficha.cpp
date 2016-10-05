//
// Created by artv23 on 30/09/16.
//

#include "Ficha.h"

Ficha::Ficha(int color, int num) : color(color), corona(false), num(num) { }

int Ficha::getColor() const {
    return color;
}

void Ficha::setColor(int color) {
    this->color = color;
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

int Ficha::getNum() {
    return num;
}

void Ficha::setNum(int num) {
    this->num = num;
}

string Ficha::toString() {
    stringstream s;

    if(color == 2)
        s << "X" << endl;
    if(color == 1)
        s << "N" << num;
    if(color == 0)
        s << "B" << num;

    if(corona)
        s << " (c)";

    return s.str();
}