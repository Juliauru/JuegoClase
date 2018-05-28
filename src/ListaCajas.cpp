#include "ListaCajas.h"
#include "Interaccion.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>


using namespace std;
ListaCajas::ListaCajas() :Box({0.0f,0.0f})
{};
	

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
		if (n > CAJASMAX) {
			cout << "Error" << endl;
			exit;
		}
		ListaCajas::Set_ncajas(n);
		lista[3] = new Box({ 0,0 });
		while (!fichero.eof() && i < n_cajas) {
			fichero >> x;
			fichero >> y;
			Vector2D aux(x, y + Long_caracteristica);
			lista[i] = new Box(aux);
			/*lista[i].getPosicion().setValor(x, (y+(Long_caracteristica)));
			lista[i].getColor().SetColor(145, 28, 226);*/
			i++;
		}
		/*if (i < n_cajas) {
			for (i; i < n_cajas; i++) {
				lista[i] = 0;
			}
		}*/ //IDEA si se reservan más memorias que numero de plataformas existan, poner ese puntero a 0 para que no se ejecute nada raro
	}
	fichero.close();
}

void ListaCajas::Dibuja()
{
	for (int i = 0; i < n_cajas; i++) {
		lista[i]->Dibuja();
	}
}
void ListaCajas::Mueve(float t)
{
	for (int i = 0; i < n_cajas; i++) {
		lista[i]->Mueve(t);
	}
}
void ListaCajas::Coger(Personaje &pers) {
	for (int i = 0; i < n_cajas; i++) {
		Interaccion::Coger(pers, *(lista[i]));
	}
}

void ListaCajas::Contacto(Personaje & pers)
{
	for (int i = 0; i < n_cajas; i++) {
		Interaccion::Contacto(pers, *(lista[i]));
	}
}

void ListaCajas::Mover(Personaje & pers)
{
	for (int i = 0; i < n_cajas; i++) {
		Interaccion::Mover(pers, *(lista[i]));
		for (int j = i+1; j <= n_cajas-1; j++) {
			Interaccion::Mover(*(lista[i]), *(lista[j]),pers);
		}
	}
}
void ListaCajas::Caida(Plataforma p) {
	for (int i = 0; i < n_cajas; i++) {
		Interaccion::Contacto(*(lista[i]),p);
	}
}


