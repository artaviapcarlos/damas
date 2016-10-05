#pragma once
#include "LinkedList.h"
#include "Integer.h"
#include "Ficha.h"

class ListaOrdenable: public LinkedList<Ficha> {
public:
	ListaOrdenable(void);
	Ficha* locate(int);
	void marcar(int);
	void addOrdenado(Ficha *e);
	void swapNodo(int,Ficha*);
	void moveUpLeft(int);
	void moveUpRight(int);
	void moveDownLeft(int);
	void moveUDownRight(int);
	Ficha* operator [] (const int index);
};

