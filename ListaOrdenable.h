#include "LinkedList.h"
#include "Casilla.h"
using namespace std;

class ListaOrdenable: public LinkedList<Casilla> {
public:
	ListaOrdenable(void);
	Casilla* locate(int);
	void marcar(int);
	void addOrdenado(Casilla *e);
	Casilla* operator [] (const int index);
	/*int CasillasComidasBlancas = 0; TABLERO
	int CasillasComidasNegras = 0;*/
	string toString();
	string toStringCasilla();
};

