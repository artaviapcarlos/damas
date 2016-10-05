#include "ListaOrdenable.h"


ListaOrdenable::ListaOrdenable(void):LinkedList<Ficha>() {
}

Ficha* ListaOrdenable::locate(int x){
	Nodo<Ficha>* tmp= root;
	while(tmp){
		if(tmp->getElemento()->getNum() == x){
			return tmp->getElemento();
		}
		else{
			tmp= tmp->getSiguiente();
		}
	}

	return NULL;
}
void  ListaOrdenable::marcar(int x){
	Nodo<Ficha>* tmp = root;
	while(tmp){
		if(tmp->getElemento()->getNum()== x){
			tmp->getElemento()->coronar();
		    return;
		}
		else
			tmp= tmp->getSiguiente();

	}
}

void ListaOrdenable::addOrdenado(Ficha* e){
	Nodo<Ficha> *nuevo = new Nodo<Ficha>(e,NULL,NULL);
	if(esVacia()){
	root= nuevo;
	last= root;
	}
	else{
		if(root->getElemento()->getNum()>nuevo->getElemento()->getNum()){
			nuevo->setSiguiente(root);
			root->setAnterior(nuevo);
			root= nuevo;
		}
		else{
		 Nodo<Ficha> *tmp= root;
		 while(e->getNum()>= tmp->getElemento()->getNum()&&tmp->getSiguiente()){
			 tmp= tmp->getSiguiente();
		 }
		 if(e->getNum()>= tmp->getElemento()->getNum()){
			 tmp->setSiguiente(nuevo);
			 nuevo->setAnterior(tmp);
		     last= nuevo;
		 }
		 else{
			 Nodo<Ficha> *tmp2= tmp->getAnterior();
			 tmp->setAnterior(nuevo);
			 nuevo->setSiguiente(tmp);
			 tmp2->setSiguiente(nuevo);
			 nuevo->setAnterior( tmp2);
		 }
		}
	}
}

void ListaOrdenable::swapNodo(int index, Ficha* ficha) {
	int color = locate(index)->getColor();
	bool corona = locate(index)->getCorona();
	int num = locate(index)->getNum();

	locate(index)->setColor(ficha->getColor());
	locate(index)->setCorona(ficha->getCorona());
	locate(index)->setNum(ficha->getNum());

	ficha->setColor(color);
	ficha->setCorona(color);
	ficha->setNum(num);
}

void ListaOrdenable::moveUpLeft(int ) {

}


Ficha* ListaOrdenable::operator[](const int index) {
	return locate(index);
}

