#include "ListaOrdenable.h"


ListaOrdenable::ListaOrdenable(void) : LinkedList<Casilla>() {
}

Casilla *ListaOrdenable::locate(int x) {
    Nodo<Casilla> *tmp = root;
    while (tmp) {
        if (tmp->getElemento()->getNum() == x) {
            return tmp->getElemento();
        }
        else {
            tmp = tmp->getSiguiente();
        }
    }

    return NULL;
}

void  ListaOrdenable::marcar(int x) {
    Nodo<Casilla> *tmp = root;
    while (tmp) {
        if (tmp->getElemento()->getNum() == x) {
            tmp->getElemento()->coronar();
            return;
        }
        else
            tmp = tmp->getSiguiente();
    }
}

void ListaOrdenable::addOrdenado(Casilla *e) {
    Nodo<Casilla> *nuevo = new Nodo<Casilla>(e, NULL, NULL);
    if (esVacia()) {
        root = nuevo;
        last = root;
    }
    else {
        if (root->getElemento()->getNum() > nuevo->getElemento()->getNum()) {
            nuevo->setSiguiente(root);
            root->setAnterior(nuevo);
            root = nuevo;
        }
        else {
            Nodo<Casilla> *tmp = root;
            while (e->getNum() >= tmp->getElemento()->getNum() && tmp->getSiguiente()) {
                tmp = tmp->getSiguiente();
            }
            if (e->getNum() >= tmp->getElemento()->getNum()) {
                tmp->setSiguiente(nuevo);
                nuevo->setAnterior(tmp);
                last = nuevo;
            }
            else {
                Nodo<Casilla> *tmp2 = tmp->getAnterior();
                tmp->setAnterior(nuevo);
                nuevo->setSiguiente(tmp);
                tmp2->setSiguiente(nuevo);
                nuevo->setAnterior(tmp2);
            }
        }
    }
}

Casilla *ListaOrdenable::operator[](const int index) {
    return locate(index);
}

string ListaOrdenable::toString() {
    stringstream s;
    /*Nodo<Casilla> *actual = root;
    s << "|";
    while (actual) {
        Casilla *obj = actual->getElemento();
        s << obj->toString();
        actual = actual->getSiguiente();
    }
    s << endl;*/

    s << toStringCasilla();
    return s.str();
}

string ListaOrdenable::toStringCasilla(){
    stringstream s;
    Nodo<Casilla> *actual = root;
    s << "|";
    while (actual) {
        Casilla *obj = actual->getElemento();
        if(obj->getUpLeft())
            s << "Casilla upLeft: " << obj->getUpLeft()->getFicha()->toString();
        if(obj->getUpRight())
            s << "Casilla upRight: " << obj->getUpRight()->getFicha()->toString();
        if(obj->getDownLeft())
            s << "Casilla downLeft: " << obj->getDownLeft()->getFicha()->toString();
        if(obj->getDownRight())
            s << "Casilla downRight: " << obj->getDownRight()->getFicha()->toString();
        s << endl;
        actual = actual->getSiguiente();
    }
    s << endl;
    return s.str();
}


