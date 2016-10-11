//
// Created by artv23 on 10/10/16.
//

#ifndef DAMAS_JUGADOR_H
#define DAMAS_JUGADOR_H

#include "Ficha.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
#include <sstream>


using namespace std;


class Jugador{
private:
    string nombre;
    int color;
    LinkedList<Ficha> *fichas;

public:
    Jugador();
    Jugador(string,int);
    void setNombre(string);
    void setColor(int);
    string getNombre();
    int getColor();
    void addFicha(Ficha*);
    Ficha * getFicha(int);
    LinkedList<Ficha>* getFichas();
    string toString();
    ~Jugador();
};

#endif //DAMAS_JUGADOR_H
