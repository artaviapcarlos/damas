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
	virtual Nodo<Ficha>* getNode(int);
	void swapNodo(int,Ficha*);
	bool moveUpLeft(Nodo<Ficha>*,int,Nodo<Ficha>*);
	bool moveUpRight(Nodo<Ficha>*,int,Nodo<Ficha>*);
	bool moveDownLeft(Nodo<Ficha>*,int,Nodo<Ficha>*);
	bool moveUDownRight(Nodo<Ficha>*,int,Nodo<Ficha>*);
	Ficha* operator [] (const int index);
};

