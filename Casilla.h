//
// Created by artv23 on 07/10/16.
//

#ifndef DAMAS_CASILLA_H
#define DAMAS_CASILLA_H


#include "Ficha.h"
#include "Nodo.h"

using namespace std;

class Casilla{
public:
    Casilla(Ficha*,int);
    bool canEat();
    bool eat();
    void swapCasilla(Casilla*);
    Ficha* getFicha() const;
    int getNum() const;
    virtual Casilla* getUpLeft() const;
    virtual Casilla* getUpRight() const;
    virtual Casilla* getDownLeft() const;
    virtual Casilla* getDownRight() const;
    virtual void setUpLeft(Casilla*);
    virtual void setUpRight(Casilla*);
    virtual void setDownLeft(Casilla*);
    virtual void setDownRight(Casilla*);
    virtual Casilla* moveUpLeft();
    virtual Casilla* moveUpRight();
    virtual Casilla* moveDownLeft();
    virtual Casilla* moveDownRight();
    virtual void coronar();
    virtual string toString();

private:
    Casilla* upLeft;
    Casilla* upRight;
    Casilla* downLeft;
    Casilla* downRight;
    Ficha* ficha;
    int num;
};


#endif //DAMAS_CASILLA_H
