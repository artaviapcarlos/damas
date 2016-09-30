
#pragma once
#include<iostream>
#include<sstream>
using namespace std;

class Integer
{
public:
	Integer(int);
	~Integer(void);
	int getValor();
	string toString();
    bool esMarcado();
	void marcar();
	void desMarcar();

private:
	int valor;
	bool marcado;


};

