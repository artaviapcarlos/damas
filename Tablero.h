
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
	void initNumeros();
	bool revisarGanador();
	bool finPartida();

private:
	LinkedList<ListaOrdenable>* listas;
	int eatenW;
	int eatenB;
};

