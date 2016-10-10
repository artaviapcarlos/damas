//
// Created by artv23 on 03/10/16.
//

#include "ListaOrdenable.h"

using namespace std;

int main(){

    ListaOrdenable* listaBlancas = new ListaOrdenable();
    ListaOrdenable* listaNegras = new ListaOrdenable();
    ListaOrdenable* A = new ListaOrdenable();
    ListaOrdenable* B = new ListaOrdenable();
    ListaOrdenable* C = new ListaOrdenable();
    ListaOrdenable* D = new ListaOrdenable();
    ListaOrdenable* E = new ListaOrdenable();
    ListaOrdenable* F = new ListaOrdenable();
    ListaOrdenable* G = new ListaOrdenable();
    ListaOrdenable* H = new ListaOrdenable();

    LinkedList<ListaOrdenable>* listas =  new LinkedList<ListaOrdenable>();

    listas->addLast(A);
    listas->addLast(B);
    listas->addLast(C);
    listas->addLast(D);
    listas->addLast(E);
    listas->addLast(F);
    listas->addLast(G);
    listas->addLast(H);
/*
    for(int i=0; i < 4; i++)
        listaBlancas->addLast(new Ficha(0,i));

    for(int i=0; i < 4; i++)
        listaNegras->addLast(new Ficha(1,i));


    cout << "Negras" << endl;
    cout << listaNegras->toString() << endl;

    cout << "\n Blancas" << endl;
    cout << listaBlancas->toString() << endl;

    listaNegras->operator[](3)->coronar();
    listaNegras->operator[](1)->coronar();

    cout << "corona" << endl;
    cout << listaNegras->toString() << endl;

    /*cout << "\n Prueba de intercambio b c/ b" << endl;
    listaBlancas->swapNodo(0,listaBlancas->locate(3));*/

   /* cout << listaBlancas->toString() << endl;

    cout << "\n Prueba de intercambio b c/ n" << endl;
    listaBlancas->swapNodo(0,listaNegras->locate(3));

    cout << "\nBlancas" << endl;
    cout << listaBlancas->toString() << endl;

    cout << "\n Negras" << endl;
    cout << listaNegras->toString() << endl;*/

    for(int i=0; i<8; i++){
        for(int j=0; j<4; j++){
            if(i>=0 && i<3)
                listas->get(i)->addLast(new Casilla(new Ficha(0),j));
            if(i>=3 && i<5)
                listas->get(i)->addLast(new Casilla(new Ficha(2),j));
            if(i>=5 && i<8)
                listas->get(i)->addLast(new Casilla(new Ficha(1),j));
        }
    }

    cout << listas->toString() << endl;

    // Creando enlaces de casillas

    for(int i=1; i<7; i+=2){
        if(i!=7) {
            for (int j = 0; j < 3; j++) {
                if (j != 3) {
                    listas->get(i)->get(j)->setUpLeft(listas->get(i - 1)->get(j));
                    listas->get(i)->get(j)->setUpRight(listas->get(i - 1)->get(j + 1));
                    listas->get(i)->get(j)->setDownLeft(listas->get(i + 1)->get(j));
                    listas->get(i)->get(j)->setDownRight(listas->get(i + 1)->get(j + 1));
                }
                else {
                    listas->get(i)->get(j)->setUpLeft(listas->get(i - 1)->get(j));
                    listas->get(i)->get(j)->setDownLeft(listas->get(i + 1)->get(j));
                }
            }
        }
        else{
            for(int j=0; j<3 ; j++){
                if (j != 3) {
                    listas->get(i)->get(j)->setUpLeft(listas->get(i - 1)->get(j));
                    listas->get(i)->get(j)->setUpRight(listas->get(i - 1)->get(j + 1));
                }
                else {
                    listas->get(i)->get(j)->setUpLeft(listas->get(i - 1)->get(j));
                }
            }
        }
    }

    // ------------------ //

    for(int i=6; i>0; i-=2){
        if(i!=0) {
            for (int j = 3; j > 0; j--) {
                if (j != 0) {
                    listas->get(i)->get(j)->setUpLeft(listas->get(i - 1)->get(j));
                    listas->get(i)->get(j)->setUpRight(listas->get(i - 1)->get(j - 1));
                    listas->get(i)->get(j)->setDownLeft(listas->get(i + 1)->get(j));
                    listas->get(i)->get(j)->setDownRight(listas->get(i + 1)->get(j - 1));
                }
                else {
                    listas->get(i)->get(j)->setUpRight(listas->get(i - 1)->get(j));
                    listas->get(i)->get(j)->setDownRight(listas->get(i + 1)->get(j));
                }
            }
        }
        else{
            for(int j=3; j>0 ; j--){
                if (j != 0) {
                    listas->get(i)->get(j)->setDownLeft(listas->get(i + 1)->get(j-1));
                    listas->get(i)->get(j)->setDownRight(listas->get(i + 1)->get(j));
                }
                else {
                    listas->get(i)->get(j)->setDownRight(listas->get(i + 1)->get(j));
                }
            }
        }
    }

    /*Casilla* mov = listas->get(2)->get(2)->moveDownRight();

    if(mov)
        cout << "Casilla: " << mov->toString() << endl;
    else
        cout << "No se pudo mover" << endl;

    cout << "-------------" << endl;

    cout << listas->toString() << endl;*/

    cout << listas->toString() << endl;


    return 0;
}