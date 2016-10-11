#include "Tablero.h"

Tablero::Tablero() {
    listas = new LinkedList<ListaOrdenable>();
    A = new Jugador();
    B = new Jugador();
    initTablero();
}

void Tablero::initTablero() {
    for(int i=0; i<8; i++){
        listas->addLast(new ListaOrdenable());
    }

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

    for(int i=1; i<7; i+=2){
        if(i<7) {
            for (int j = 0; j < 3; j++) {
                if (j < 3) {
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
                if (j < 3) {
                    listas->get(i)->get(j)->setUpLeft(listas->get(i - 1)->get(j));
                    listas->get(i)->get(j)->setUpRight(listas->get(i - 1)->get(j + 1));
                }
                else {
                    listas->get(i)->get(j)->setUpLeft(listas->get(i - 1)->get(j));
                }
            }
        }
    }

    for(int i=6; i>0; i-=2){
        if(i!=0) {
            for (int j = 3; j > 0; j--) {
                if (j > 0) {
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
                if (j > 0) {
                    listas->get(i)->get(j)->setDownLeft(listas->get(i + 1)->get(j-1));
                    listas->get(i)->get(j)->setDownRight(listas->get(i + 1)->get(j));
                }
                else {
                    listas->get(i)->get(j)->setDownRight(listas->get(i + 1)->get(j));
                }
            }
        }
    }

}

int Tablero::revisarGanador(){

}

bool Tablero::finPartida(){

}

int Tablero::cantFichas(int color){

}

bool Tablero::tieneMovs(int color){

}

bool Tablero::moverFicha(Casilla* a, int color, int mov){
    if(a->hasMoves()) {
        switch (mov) {
            case 0: {
                Casilla* aux = a->moveUpLeft();
                if (aux)
                    return true;
                cout << "No puede hacer este movimiento (arriba izq)" << endl;
                return false;
            }
            break;
            case 1: {
                Casilla* aux = a->moveUpRight();
                if (aux)
                    return true;
                cout << "No puede hacer este movimiento (arriba der)" << endl;

                return false;
            }
                break;
            case 2: {
                Casilla* aux = a->moveDownLeft();
                if (aux)
                    return true;
                cout << "No puede hacer este movimiento (abajo izq)" << endl;
                return false;
            }
                break;
            case 3: {
                Casilla* aux = a->moveDownRight();
                if (aux)
                    return true;
                cout << "No puede hacer este movimiento (abajo der)" << endl;
                return false;
            }
                break;
        }
    }
    return false;
}

bool Tablero::jugadorRetirado(){

}

Casilla* Tablero::getCasilla(int row, int col) {
    return listas->get(row)->get(col);
}

Jugador* Tablero::getPlayerA(){
    return A;
}

Jugador* Tablero::getPlayerB(){
    return B;
}

string Tablero::toString() {
    stringstream s;

    s << listas->toString() << endl;

    return s.str();
}
