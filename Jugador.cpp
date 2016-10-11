//
// Created by artv23 on 10/10/16.
//

#include "Jugador.h"

Jugador::Jugador(){
    nombre = " ";
    color = 0;
    fichas = new LinkedList<Ficha>();
}

Jugador::Jugador(string nombre, int c) {
    this->nombre = nombre;
    color = c;
}

void Jugador::setNombre(string nom){
    nombre = nom;
}
void Jugador::setColor(int c){
    color = c;
}

string Jugador:: getNombre(){
    return nombre;
}
int Jugador::getColor() {
    return color;
}

void Jugador::addFicha(Ficha *ficha) {
    fichas->addLast(ficha);
}

Ficha* Jugador::getFicha(int f) {
    return fichas->get(f);
}

LinkedList<Ficha>* Jugador::getFichas(){
    return fichas;
}

string Jugador::toString(){
    stringstream s;
    cout << "Nombre: " << nombre << endl;
    if (color == 0){
        cout << "Color Negro" << endl;
    }
    else{
        cout << "Color Blanco" << endl;
    }
    return s.str();
}

Jugador::~Jugador() {
}