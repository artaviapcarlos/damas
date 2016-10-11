
#include"ListaOrdenable.h"
#include"Integer.h"
#include<time.h>

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
	bool moverFicha(int,int,int);
	bool jugadorRetirado();

private:
	LinkedList<ListaOrdenable>* listas;
	int eatenW;
	int eatenB;
};

