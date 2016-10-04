/*
#include "Tablero.h"


Tablero::Tablero(void) {
    initTablero();
}


Tablero::~Tablero(void) {
}


string Tablero::toString() {

    stringstream s;
    //s<<" VERTICAL"<<endl;
    // s<<vertical->toString();
    s << "Horizontal" << endl;
    s << horizontal->toString();

    //s<<diagonal->toString();
    return s.str();
}


void Tablero::initNumeros() {
    int cont = 0;
    B = new Integer *[15];
    for (int i = 1; i <= 15; i++) {
        B[i - 1] = new Integer(i);
    }
    I = new Integer *[15];
    for (int i = 16; i <= 30; i++) {
        I[cont] = new Integer(i);
        cont++;
    }
    cont = 0;
    N = new Integer *[15];
    for (int i = 31; i <= 45; i++) {
        N[cont] = new Integer(i);
        cont++;
    }
    cont = 0;
    G = new Integer *[15];
    for (int i = 46; i <= 60; i++) {
        G[cont] = new Integer(i);
        cont++;
    }
    cont = 0;
    O = new Integer *[15];
    for (int i = 61; i <= 75; i++) {
        O[cont] = new Integer(i);
        cont++;
    }


    knuthShuffle(B);
    cout << "." << endl;
    knuthShuffle(I);
    cout << "." << endl;
    knuthShuffle(N);
    cout << "." << endl;
    knuthShuffle(G);
    cout << "." << endl;
    knuthShuffle(O);
    cout << "." << endl;

}

void Tablero::initTablero() {
    initNumeros();


    vertical = new LinkedList<ListaOrdenable>();
    horizontal = new LinkedList<ListaOrdenable>();
    diagonal = new LinkedList<ListaOrdenable>();

    // se crea el tablero con vertical
    ListaOrdenable *list1 = new ListaOrdenable();
    for (int i = 0; i < 5; i++) {
        list1->addLast(B[i]);
    }
    vertical->addLast(list1);

    ListaOrdenable *list2 = new ListaOrdenable();
    for (int i = 0; i < 5; i++) {
        list2->addLast(I[i]);
    }
    vertical->addLast(list2);

    ListaOrdenable *list3 = new ListaOrdenable();
    for (int i = 0; i < 5; i++) {
        list3->addLast(N[i]);
    }
    vertical->addLast(list3);

    ListaOrdenable *list4 = new ListaOrdenable();
    for (int i = 0; i < 5; i++) {
        list4->addLast(G[i]);
    }
    vertical->addLast(list4);

    ListaOrdenable *list5 = new ListaOrdenable();
    for (int i = 0; i < 5; i++) {
        list5->addLast(O[i]);
    }
    vertical->addLast(list5);
    // se crea el horizontal a partir de vertical
    ListaOrdenable *list6 = new ListaOrdenable();
    list6->addLast(B[0]);
    list6->addLast(I[0]);
    list6->addLast(N[0]);
    list6->addLast(G[0]);
    list6->addLast(O[0]);
    horizontal->addLast(list6);

    ListaOrdenable *list7 = new ListaOrdenable();
    list7->addLast(B[1]);
    list7->addLast(I[1]);
    list7->addLast(N[1]);
    list7->addLast(G[1]);
    list7->addLast(O[1]);
    horizontal->addLast(list7);

    ListaOrdenable *list8 = new ListaOrdenable();
    list8->addLast(B[2]);
    list8->addLast(I[2]);
    list8->addLast(N[2]);
    list8->addLast(G[2]);
    list8->addLast(O[2]);
    horizontal->addLast(list8);

    ListaOrdenable *list9 = new ListaOrdenable();
    list9->addLast(B[3]);
    list9->addLast(I[3]);
    list9->addLast(N[3]);
    list9->addLast(G[3]);
    list9->addLast(O[3]);
    horizontal->addLast(list9);

    ListaOrdenable *list10 = new ListaOrdenable();
    list10->addLast(B[4]);
    list10->addLast(I[4]);
    list10->addLast(N[4]);
    list10->addLast(G[4]);
    list10->addLast(O[4]);
    horizontal->addLast(list10);

    // se crea la lista diagonal
    ListaOrdenable *list11 = new ListaOrdenable();
    list11->addLast(B[0]);
    list11->addLast(I[1]);
    list11->addLast(N[2]);
    list11->addLast(G[3]);
    list11->addLast(O[4]);
    diagonal->addLast(list11);

    ListaOrdenable *list12 = new ListaOrdenable();
    list12->addLast(B[4]);
    list12->addLast(I[3]);
    list12->addLast(N[2]);
    list12->addLast(G[1]);
    list12->addLast(O[0]);
    diagonal->addLast(list12);

}

void Tablero::knuthShuffle(Integer **orgArray) {
    int arraySize = 15;


    if (arraySize == 0 || arraySize == 1)
        return;

    srand(time(NULL));

    int i;
    int index;
    Integer *temp;
    for (i = arraySize - 1; i > 0; i--) {
        index = rand() % (i + 1);
        temp = orgArray[index];
        orgArray[index] = orgArray[i];
        orgArray[i] = temp;
    }

}

void Tablero::marcarNumero(int b, int a) {

    Nodo<ListaOrdenable> *tmp = vertical->getRoot();

    if (b == 1) {
        vertical->getRoot()->getElemento()->marcar(a);
    }
    while (b != 1) {
        tmp = tmp->getSiguiente();
        b--;
    }
    tmp->getElemento()->marcar(a);


}

bool Tablero::revisarvert() {
    Nodo<ListaOrdenable> *aux = vertical->getRoot();
    int cont = 0;
    while (aux) {
        for (int i = 0; i < 5; i++) {
            if (aux->getElemento()->get(i)->esMarcado()) {
                cont++;
            }
        }
        if (cont == 5)return true;
        cont = 0;
        aux = aux->getSiguiente();
    }
    return false;
}


bool Tablero::revisarhori() {
    Nodo<ListaOrdenable> *aux = horizontal->getRoot();
    int cont = 0;
    while (aux) {
        for (int i = 0; i < 5; i++) {
            if (aux->getElemento()->get(i)->esMarcado()) {
                cont++;
            }
        }
        if (cont == 5)return true;
        cont = 0;
        aux = aux->getSiguiente();
    }
    return false;
}


bool Tablero::revisardiago() {
    Nodo<ListaOrdenable> *aux = diagonal->getRoot();
    int cont = 0;
    while (aux) {
        for (int i = 0; i < 5; i++) {
            if (aux->getElemento()->get(i)->esMarcado()) {
                cont++;
            }
        }
        if (cont == 5)return true;
        cont = 0;
        aux = aux->getSiguiente();
    }
    return false;
}

bool Tablero::revisaro() {
    Nodo<ListaOrdenable> *aux = horizontal->getRoot();
    int cont = 0;
    for (int i = 0; i < 5; i++) {
        if (aux->getElemento()->get(i)->esMarcado()) {
            cont++;
        }
    }
    if (cont != 5)return false;
    cont = 0;
    for (int i = 0; i < 5; i++) {
        if (aux->getSiguiente()->getSiguiente()->getSiguiente()->getSiguiente()->getElemento()->get(i)->esMarcado()) {
            cont++;
        }
    }
    if (cont != 5)return false;
    cont = 0;
    aux = vertical->getRoot();
    for (int i = 0; i < 5; i++) {
        if (aux->getElemento()->get(i)->esMarcado()) {
            cont++;
        }
    }
    if (cont != 5)return false;
    cont = 0;
    for (int i = 0; i < 5; i++) {
        if (aux->getSiguiente()->getSiguiente()->getSiguiente()->getSiguiente()->getElemento()->get(i)->esMarcado()) {
            cont++;
        }
    }
    if (cont != 5)return false;

    return true;
}

bool Tablero::revisarc() {
    Nodo<ListaOrdenable> *aux = horizontal->getRoot();
    int cont = 0;
    for (int i = 0; i < 5; i++) {
        if (aux->getElemento()->get(i)->esMarcado()) {
            cont++;
        }
    }
    if (cont != 5)return false;
    cont = 0;
    for (int i = 0; i < 5; i++) {
        if (aux->getSiguiente()->getSiguiente()->getSiguiente()->getSiguiente()->getElemento()->get(i)->esMarcado()) {
            cont++;
        }
    }
    if (cont != 5)return false;
    cont = 0;
    aux = vertical->getRoot();
    for (int i = 0; i < 5; i++) {
        if (aux->getElemento()->get(i)->esMarcado()) {
            cont++;
        }
    }
    if (cont != 5)return false;

    return true;

}

bool Tablero::revisaru() {
    Nodo<ListaOrdenable> *aux = horizontal->getRoot();
    int cont = 0;
    for (int i = 0; i < 5; i++) {
        if (aux->getSiguiente()->getSiguiente()->getSiguiente()->getSiguiente()->getElemento()->get(i)->esMarcado()) {
            cont++;
        }
    }
    if (cont != 5)return false;
    cont = 0;
    aux = vertical->getRoot();
    for (int i = 0; i < 5; i++) {
        if (aux->getElemento()->get(i)->esMarcado()) {
            cont++;
        }
    }
    if (cont != 5)return false;
    cont = 0;
    for (int i = 0; i < 5; i++) {
        if (aux->getSiguiente()->getSiguiente()->getSiguiente()->getSiguiente()->getElemento()->get(i)->esMarcado()) {
            cont++;
        }
    }
    if (cont != 5)return false;

    return true;

}

bool Tablero::revisarlleno() {
    Nodo<ListaOrdenable> *aux = horizontal->getRoot();
    int cont = 0;
    while (aux) {
        for (int i = 0; i < 5; i++) {
            if (aux->getElemento()->get(i)->esMarcado()) {
                cont++;
            }
        }
        if (cont != 5)return false;
        cont = 0;
        aux = aux->getSiguiente();
    }
    return true;


}


bool Tablero::revisarx() {
    Nodo<ListaOrdenable> *aux = diagonal->getRoot();
    int cont = 0;
    while (aux) {
        for (int i = 0; i < 5; i++) {
            if (aux->getElemento()->get(i)->esMarcado()) {
                cont++;
            }
        }
        if (cont != 5)return false;
        cont = 0;
        aux = aux->getSiguiente();
    }
    return true;

}

void Tablero::finalizaPartida() {
    Nodo<ListaOrdenable> *aux = horizontal->getRoot();
    while (aux) {
        for (int i = 0; i < 5; i++) {
            aux->getElemento()->get(i)->desMarcar();

        }
        aux = aux->getSiguiente();
    }
}
	
	




	
	
	
	*/
