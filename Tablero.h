
#include"ListaOrdenable.h"
#include"Integer.h"
#include<time.h>
#include<Windows.h>

#pragma once
class Tablero
{
	
public:
	Tablero();
	~Tablero();
	string toString();
	void initTablero();
	void initNumeros();
	void static knuthShuffle(Integer** orgArray);
	void marcarNumero(int, int);
	bool revisarlleno();
	bool revisarvert();
	bool revisarhori();
	bool revisardiago();
	bool revisarc();
	bool revisarx();
	bool revisaru();
	bool revisaro();
	void finalizaPartida();

private:
	LinkedList<ListaOrdenable>* vertical;
	LinkedList<ListaOrdenable>* horizontal;
	LinkedList<ListaOrdenable>* diagonal;
	 Integer** B;
	 Integer** I;
	 Integer** N;
	 Integer** G;
	 Integer** O;

};

