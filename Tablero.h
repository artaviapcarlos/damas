
#include"ListaOrdenable.h"
#include"Integer.h"
#include<time.h>
#include "Jugador.h"

#pragma once
class Tablero
{
	
public:
	Tablero();
	~Tablero();
	string toString();
	void initTablero();
	int revisarGanador();
	bool finPartida();
	int cantFichas(int);
	bool tieneMovs(int);
	bool moverFicha(Casilla*,int,int);
	bool jugadorRetirado();
	Casilla* getCasilla(int,int);
	Jugador* getPlayerA();
	Jugador* getPlayerB();

private:
	LinkedList<ListaOrdenable>* listas;
	Jugador* A;
	Jugador* B;
	int eatenW;
	int eatenB;
};

