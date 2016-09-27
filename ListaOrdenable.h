#pragma once
#include "LinkedList.h"
#include"Integer.h"

class ListaOrdenable: public LinkedList<Integer>
{
public:
	ListaOrdenable(void);
	Integer* locate(int);
	void marcar(int);
	void addOrdenado(Integer *e);
};

