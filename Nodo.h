#pragma once
#include<iostream>

using namespace std;

template <class T>
class Nodo
{
protected:
	T *elemento;
	Nodo<T>* siguiente;
	Nodo<T>* anterior;
	Nodo<T>* upLeft;
	Nodo<T>* upRight;
	Nodo<T>* downLeft;
	Nodo<T>* downRight;
	int col;

public:
	Nodo(T*,Nodo<T> *s = NULL,Nodo<T> *p = NULL);
	virtual Nodo<T> *getSiguiente()const;
	virtual Nodo<T> *getAnterior()const;
	virtual T *getElemento()const;
	virtual void setSiguiente(Nodo<T>*);
	virtual void setAnterior(Nodo<T>*);
	virtual Nodo* getUpLeft() const;
	virtual Nodo* getUpRight() const;
	virtual Nodo* getDownLeft() const;
	virtual Nodo* getDownRight() const;
	virtual void setUpLeft(Nodo<T>*);
	virtual void setUpRight(Nodo<T>*);
	virtual void setDownLeft(Nodo<T>*);
	virtual void setDownRight(Nodo<T>*);
	virtual ~Nodo();
};

template <class T>
Nodo<T>::Nodo(T* dato,Nodo<T> *ant,Nodo<T>*sig)
{
	this->siguiente = sig;
	this->elemento = dato;
	this->anterior = ant;
}

template <class T>
void Nodo<T>::setSiguiente(Nodo<T>* n){
	siguiente = n;
}

template <class T>
void Nodo<T>::setAnterior(Nodo<T>* n){
	anterior = n;
}

template <class T>
 Nodo<T>* Nodo<T>::getSiguiente()const
{
	return siguiente;
}

 template <class T>
 Nodo<T>* Nodo<T>::getAnterior()const
{
	return anterior;
}


template <class T>
T *Nodo<T>::getElemento()const
{
	return elemento;
}

template <class T>
Nodo<T>* Nodo<T>::getUpLeft() const {
	return upLeft;
}

template <class T>
void Nodo<T>::setUpLeft(Nodo<T> *upLeft) {
	this->upLeft = upLeft;
}

template <class T>
Nodo<T>* Nodo<T>::getUpRight() const {
	return upRight;
}

template <class T>
void Nodo<T>::setUpRight(Nodo<T> *upRight) {
	this->upRight = upRight;
}

template <class T>
Nodo<T>* Nodo<T>::getDownLeft() const {
	return downLeft;
}

template <class T>
void Nodo<T>::setDownLeft(Nodo<T> *downLeft) {
	this->downLeft = downLeft;
}

template <class T>
Nodo<T> *Nodo<T>::getDownRight() const {
	return downRight;
}

template <class T>
void Nodo<T>::setDownRight(Nodo<T> *downRight) {
	this->downRight = downRight;
}

template <class T>
 Nodo<T>::~Nodo()
{
	
}