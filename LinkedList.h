#pragma once;
#include<iostream>
#include<sstream>
#include"Nodo.h"

using namespace std;

template <class T>
class LinkedList
{
protected:
	Nodo<T>*root;
	Nodo<T>* actual;
	Nodo<T>* last;
public:
	LinkedList();
	virtual void addRoot(T*);
	virtual void addLast(T*);
	virtual void eliminarFinal();
	virtual Nodo<T>* getRoot();
	virtual void eliminarInicio();
	virtual string toString();
	virtual bool esVacia();
	virtual int longitud();
	virtual T* get(int);
	~LinkedList();
};

template <class T>
LinkedList<T>::LinkedList()
{
	root=NULL;
	last= NULL;
}

template <class T>
 T* LinkedList<T>::get(int x)
{
	 Nodo<T>* tmp= root;
    int k= 0;
	while(tmp!=NULL){
		if(k== x){
			return tmp->getElemento();
		
		}
		else{
			tmp= tmp->getSiguiente();
                        k++;
		}
	}
       
        return NULL;
	
}




template <class T>
bool LinkedList<T>::esVacia()
{
	return root==NULL;
}

template <class T>
  void LinkedList<T>::addRoot(T* e){
    if(esVacia()){
    root= new Nodo<T>(e,NULL,NULL);
    last= root;
    }
    else{
    Nodo<T> *n= new Nodo<T>(e,NULL,root);
    root->setAnterior(n);
    root= n;
            }
    }

  template <class T>
   Nodo<T> * LinkedList<T>::getRoot(){
   return root;
    }


  template <class T>
  void LinkedList<T>::addLast(T* e){
   if(esVacia()){
    addRoot(e);
    }
    else{
        Nodo<T> *tmp= new Nodo<T>(e,last,NULL);
       last->setSiguiente(tmp);
       last= tmp;
    }
  }

   template <class T>
 int LinkedList<T>:: longitud()
{
	int cantidad = 0;

	Nodo<T>* actual = root;
	while(actual){
		actual = actual -> getSiguiente();
		cantidad++;
	}
	return cantidad;
}

 template <class T>
 string LinkedList<T>::toString()
{
	stringstream s;
	Nodo<T>* actual=root;
	while(actual)
	{
		T *obj=actual->getElemento();
		  s<<obj->toString();
		actual=actual->getSiguiente();
	}
	s<<endl;
	return s.str();
}

 template <class T>
 void LinkedList<T>::eliminarInicio(){
if(!esVacia()){
		Nodo<T>* actual = root;
		actual->getSiguiente()->setAnterior(NULL);
		root= actual->getSiguiente();
		actual->setSiguiente(NULL);		
		delete actual;

	}
}

 template <class T>
 void LinkedList<T>::eliminarFinal(){
	 if(!esVacia()){
	 Nodo<T>* actual = last;
	 last= actual->getAnterior();
	 last->setSiguiente(NULL);
	 actual->setAnterior(NULL);
	 delete actual;
	 
	 }
 }



  
  
  






