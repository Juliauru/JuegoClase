#include "ListaCajas.h"
#include "Interaccion.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>


using namespace std;
ListaCajas::ListaCajas() :Box({0.0f,0.0f})
{
	n_cajas = 0;
	/*for (int i = 0; i < CAJASMAX; i++) {
		lista[i] = 0;
	}*/
}
	

ListaCajas::~ListaCajas(){}

void ListaCajas::Set_ncajas(int num)
{
	if (num < 0) {
		num = 0;
	}
	else {
		n_cajas = num;
	}
}

void ListaCajas::CreaCajas(const char *fich)
{
	f = new char[strlen(fich)];
	strcpy(f, fich);
	int n, i = 0;
	float x, y;
	ifstream fichero(f); //"Cajas.txt"
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
			Vector aux(x, y + Long_caracteristica);
			lista[i] = new Box(aux);
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

void ListaCajas::Mover(Personaje & pers,Llave &llave)
{
	for (int i = 0; i < n_cajas; i++) {
		Interaccion::Mover(pers, *(lista[i]));
		Interaccion::Mover(*(lista[i]), llave, pers);
		for (int j = i+1; j <= n_cajas-1; j++) {
			Interaccion::Mover(*(lista[i]), *(lista[j]),pers);
		}
	}
}
void ListaCajas::DestruirContenido()
{
	for (int i = 0; i < n_cajas; i++) {
		delete lista[i];
	}
	n_cajas = 0;
}
void ListaCajas::Caida(Plataforma p) {
	for (int i = 0; i < n_cajas; i++) {
		Interaccion::Contacto(*(lista[i]),p);
	}
}
void ListaCajas::Rebote(Escenario e) {
	for (int i = 0; i < n_cajas; i++) {
		Interaccion::Rebote(*(lista[i]), e);
	}
}


