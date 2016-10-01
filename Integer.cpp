#include "Integer.h"


Integer::Integer(int e)
{
	marcado= false;
	valor= e;
}


Integer::~Integer(void)
{
}

string Integer::toString(){
	stringstream s;
	if(!esMarcado()){
		s<<"["<<valor<<"]";}
	else{
		s<<"[X]";
	}
	return s.str();
}

int Integer::getValor(){
	return valor;
}

bool Integer::esMarcado(){
	return marcado;
}

void Integer::marcar(){
	marcado= true;
}

void Integer::desMarcar(){
	marcado= false;
}