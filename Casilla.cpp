//
// Created by artv23 on 07/10/16.
//

#include "Casilla.h"

Casilla::Casilla(Ficha* ficha, int num) : ficha(ficha), num(num){
}

bool Casilla::canEat() {

}

bool Casilla::eat() {

}

void Casilla::swapCasilla(Casilla* casilla) {
    int color = ficha->getColor();
    bool corona = ficha->getCorona();

    ficha->setColor(casilla->getFicha()->getColor());
    ficha->setCorona(casilla->getFicha()->getCorona());

    casilla->getFicha()->setColor(color);
    casilla->getFicha()->setCorona(corona);
}

Ficha* Casilla::getFicha() const {
    return ficha;
}

int Casilla::getNum() const {
    return num;
}

Casilla* Casilla::getUpLeft() const {
    return upLeft;
}

Casilla* Casilla::getUpRight() const {
    return upRight;
}

Casilla* Casilla::getDownLeft() const {
    return downLeft;
}

Casilla* Casilla::getDownRight() const {
    return downRight;
}


void Casilla::setUpLeft(Casilla *upLeft) {
    this->upLeft = upLeft;
}

void Casilla::setUpRight(Casilla *upRight) {
    this->upRight = upRight;
}

void Casilla::setDownLeft(Casilla *downLeft) {
    this->downLeft = downLeft;
}

void Casilla::setDownRight(Casilla *downRight) {
    this->downRight = downRight;
}

void Casilla::coronar() {
    switch(ficha->getColor()){
        case 0:
            if(!getUpLeft() && !getUpRight())
                ficha->coronar();
            break;

        case 1:
            if(!getDownLeft() && !getDownRight())
                ficha->coronar();
            break;

        default:
            break;
    }
}

Casilla* Casilla::moveUpLeft() {
    Casilla *right = getUpRight();
    int rightColor = 2;
    if (right)
        rightColor = right->getFicha()->getColor();
    if (getUpLeft()) {
        if ((ficha->getColor() == getUpLeft()->getFicha()->getColorOpos()) && rightColor == 2) {
            if (getUpLeft()->getUpLeft()) {
                swapCasilla(getUpLeft()->getUpLeft());
                getUpLeft()->getUpLeft()->coronar();
                return getUpLeft()->getUpLeft();
            }
        }
        if (getUpLeft()->getFicha()->getColor() == ficha->getColor())
            return NULL;
        if (getUpLeft()->getFicha()->getColor() == 2) {
            swapCasilla(getUpLeft());
            getUpLeft()->coronar();
            return getUpLeft();
        }

    }
    return NULL;
}

Casilla* Casilla::moveUpRight() {
    Casilla *left = getUpLeft();
    int leftColor = 2;
    if (left)
        leftColor = left->getFicha()->getColor();
    if (getUpRight()) {
        if ((ficha->getColor() == getUpRight()->getFicha()->getColorOpos()) && leftColor == 2) {
            if (getUpRight()->getUpRight()) {
                swapCasilla(getUpRight()->getUpRight());
                getUpRight()->getUpRight()->coronar();
                return getUpRight()->getUpRight();
            }
        }
        if (getUpRight()->getFicha()->getColor() == ficha->getColor())
            return NULL;
        if (getUpRight()->getFicha()->getColor() == 2) {
            swapCasilla(getUpRight());
            getUpRight()->coronar();
            return getUpRight();
        }

    }
    return NULL;
}

Casilla* Casilla::moveDownLeft() {
    Casilla *right = getDownRight();
    int rightColor = 2;
    if (right)
        rightColor = right->getFicha()->getColor();
    if (getDownLeft()) {
        if ((ficha->getColor() == getDownLeft()->getFicha()->getColorOpos()) && rightColor == 2) {
            if (getDownLeft()->getDownLeft()) {
                swapCasilla(getDownLeft()->getDownLeft());
                getDownLeft()->getDownLeft()->coronar();
                return getDownLeft()->getDownLeft();
            }
        }
        if (getDownLeft()->getFicha()->getColor() == ficha->getColor())
            return NULL;
        if (getDownLeft()->getFicha()->getColor() == 2) {
            swapCasilla(getDownLeft());
            getDownLeft()->coronar();
            return getDownLeft();
        }

    }
    return NULL;
}

Casilla* Casilla::moveDownRight() {
    Casilla *left = getDownLeft();
    int leftColor = 2;
    if (right)
        leftColor = left->getFicha()->getColor();
    if (getDownRight()) {
        if ((ficha->getColor() == getDownRight()->getFicha()->getColorOpos()) && leftColor == 2) {
            if (getDownRight()->getDownRight()) {
                swapCasilla(getDownRight()->getDownRight());
                getUpLeft()->getDownRight()->coronar();
                return getDownRight()->getDownRight();
            }
        }
        if (getDownRight()->getFicha()->getColor() == ficha->getColor())
            return NULL;
        if (getDownRight()->getFicha()->getColor() == 2) {
            swapCasilla(getDownRight());
            getDownRight()->coronar();
            return getDownRight();
        }
    }
    return NULL;
}

string Casilla::toString() {
    stringstream s;

    s << ficha->toString() << num ;

    return s.str();
}



