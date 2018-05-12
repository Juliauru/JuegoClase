#include "ListaCajas.h"
#include "Interaccion.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>


using namespace std;
ListaCajas::ListaCajas()
{
}


ListaCajas::~ListaCajas()
{
}

void ListaCajas::Set_ncajas(int num)
{
	if (num < 0) {
		num = 0;
	}
	else {
		n_cajas = num;
	}
}

void ListaCajas::CreaCajas()
{
	int n, i = 0;
	float x, y;
	ifstream fichero("Cajas.txt");
	if (!fichero)
		cout << "No se puede abrir el fichero" << endl;
	else {
		/*while (!fichero.eof()) {
			fichero >> x;
			fichero >> y;
			n++;
		}*/ ///Si en vez de tener que meter numero de cajas quiero que cuente el numero de lineas del fichero NO ESTA BIEN IMPLEMENTADO
		fichero >> n;
		ListaCajas::Set_ncajas(n);
		lista = new Box[n_cajas];
		while (!fichero.eof() && i < n_cajas) {
			fichero >> x;
			fichero >> y;
			lista[i].getPosicion().setValor(x, (y+(Long_caracteristica)/2));
			lista[i].getColor().SetColor(145, 28, 226);
			i++;
		}
		/*if (i < n_cajas) {
			for (i; i < n_cajas; i++) {
				lista[i] = 0;
			}
		}*/ //IDEA si se reservan m�s memorias que numero de plataformas existan, poner ese puntero a 0 para que no se ejecute nada raro
	}
}

void ListaCajas::Dibuja()
{
	for (int i = 0; i < n_cajas; i++) {
		lista[i].Dibuja();
	}
}
void ListaCajas::Coger(Personaje &pers) {
	for (int i = 0; i < n_cajas; i++) {
		Interaccion::Coger(pers, (lista[i]));
	}
}