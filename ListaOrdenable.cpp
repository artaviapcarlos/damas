#include "ListaOrdenable.h"


ListaOrdenable::ListaOrdenable(void):LinkedList<Integer>()
{
}

Integer* ListaOrdenable::locate(int x){
	Nodo<Integer>* tmp= root;
	while(tmp){
		if(tmp->getElemento()->getValor() == x){
			return tmp->getElemento();
		}
		else{
			tmp= tmp->getSiguiente();
		}
	}

	return NULL;
}
void  ListaOrdenable::marcar(int x){
	Nodo<Integer>* tmp = root;
	while(tmp){
		if(tmp->getElemento()->getValor()== x){
			tmp->getElemento()->marcar();
		    return;
		}
		else
			tmp= tmp->getSiguiente();

	}
}

void ListaOrdenable::addOrdenado(Integer* e){
	Nodo<Integer> *nuevo = new Nodo<Integer>(e,NULL,NULL);
	if(esVacia()){
	root= nuevo;
	last= root;
	}
	else{
		if(root->getElemento()->getValor()>nuevo->getElemento()->getValor()){
			nuevo->setSiguiente(root);
			root->setAnterior(nuevo);
			root= nuevo;
		}
		else{
		 Nodo<Integer> *tmp= root;
		 while(e->getValor()>= tmp->getElemento()->getValor()&&tmp->getSiguiente()){
			 tmp= tmp->getSiguiente();
		 }
		 if(e->getValor()>= tmp->getElemento()->getValor()){
			 tmp->setSiguiente(nuevo);
			 nuevo->setAnterior(tmp);
		     last= nuevo;
		 }
		 else{
			 Nodo<Integer> *tmp2= tmp->getAnterior();
			 tmp->setAnterior(nuevo);
			 nuevo->setSiguiente(tmp);
			 tmp2->setSiguiente(nuevo);
			 nuevo->setAnterior( tmp2);
		 }
		
		
		}
	
	}


}

