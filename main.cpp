//
// Created by artv23 on 03/10/16.
//

#include "ListaOrdenable.h";

using namespace std;

int main(){

    ListaOrdenable* listaBlancas = new ListaOrdenable();
    ListaOrdenable* listaNegras = new ListaOrdenable();

    for(int i=0; i < 4; i++)
        listaBlancas->addLast(new Ficha(0,i));

    for(int i=0; i < 4; i++)
        listaNegras->addLast(new Ficha(1,i));


    cout << "Jello" << endl;
    cout << listaNegras->toString() << endl;
    return 0;
}