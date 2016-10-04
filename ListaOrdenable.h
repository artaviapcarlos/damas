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
	Ficha* operator [] (const int index);
};

