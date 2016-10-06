
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
	ListaOrdenable* A;
	ListaOrdenable* B;
	ListaOrdenable* C;
	ListaOrdenable* D;
	ListaOrdenable* E;
	ListaOrdenable* F;
	ListaOrdenable* G;
	ListaOrdenable* H;

};

