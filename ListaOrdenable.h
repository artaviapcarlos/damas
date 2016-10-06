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
	Nodo<Ficha>* getNode(int);
	bool comerFicha(Ficha*);
	void swapNodo(Nodo<Ficha>*,Nodo<Ficha>*);
	bool moveUpLeft(Nodo<Ficha>*,Nodo<Ficha>*,int,bool);
	bool moveUpRight(Nodo<Ficha>*,Nodo<Ficha>*,int,bool);
	bool moveDownLeft(Nodo<Ficha>*,Nodo<Ficha>*,int,bool);
	bool moveUDownRight(Nodo<Ficha>*,Nodo<Ficha>*,int,bool);
	Ficha* operator [] (const int index);
	int fichasComidasBlancas = 0;
	int fichasComidasNegras = 0;
};

