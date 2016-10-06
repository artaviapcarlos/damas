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
	root = nuevo;
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

void ListaOrdenable::swapNodo(Nodo<Ficha>* node, Nodo<Ficha>* ficha) {
	int color = node->getElemento()->getColor();
	bool corona = node->getElemento()->getCorona();
	int num = node->getElemento()->getNum();

	node->getElemento()->setColor(ficha->getElemento()->getColor());
	node->getElemento()->setCorona(ficha->getElemento()->getCorona());
	node->getElemento()->setNum(ficha->getElemento()->getNum());

	ficha->getElemento()->setColor(color);
	ficha->getElemento()->setCorona(corona);
	ficha->getElemento()->setNum(num);
}

Nodo<Ficha>* ListaOrdenable::getNode(int index) {
	Nodo<Ficha>* tmp = root;
	int k = 0;
	while(tmp!=NULL){
		if(k == index){
			return tmp;
		}
		else{
			tmp = tmp->getSiguiente();
			k++;
		}
	}
	return NULL;
}

bool ListaOrdenable::comerFicha(Ficha *ficha) {
	if(ficha->getColor()==0){
		ficha->setColor(2);
		fichasComidasBlancas++;
		return true;
	}

	if(ficha->getColor()==1){
		ficha->setColor(2);
		fichasComidasNegras++;
		return true;
	}

	return false;

}

bool ListaOrdenable::moveUpLeft(Nodo<Ficha>* nodo, Nodo<Ficha>* next, int times, bool ate) {
	Ficha* ficha = nodo->getElemento();
	Nodo<Ficha>* right = next->getUpRight();
	int rightColor = 2;
	if(right)
		rightColor = right->getElemento()->getColor();
	if(next){
		if(times == 0) {
			//swapNodo()
		}
		switch(ficha->getColor()){
			case 0: {
				if(ficha->getCorona()){

				}
				else{
					if(next->getElemento()->getColor() == 1 && rightColor==2){ //PROBAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAR
						if(next->getUpLeft()){
							swapNodo(nodo,next->getUpLeft());
							comerFicha(next->getElemento());
							ate = true;
							return moveUpLeft(next->getUpLeft(),next->getUpLeft()->getUpLeft(),1,ate);
						}
					}
					if(next->getElemento()->getColor() == 0)
						return false;
					if(next->getElemento()->getColor() == 2 && ate)
						return false;
					else{
						swapNodo(nodo,next);
						return true;
					}
				}
			}
		}
	}
	else{
		if(!next && !right)
			ficha->coronar();
	}
}


Ficha* ListaOrdenable::operator[](const int index) {
	return locate(index);
}

