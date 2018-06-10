#include "ListaEnemigos.h"
#include "EnemigoD.h"
#include "Escenario.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;
ListaEnemigos::ListaEnemigos():Enemigo({0.0f,0.0f})
{
	numero = 0;
	/*for (int i = 0; i < MAX_ENEMIGOS; i++) {
		lista[i] = 0;
	}*/

}
ListaEnemigos::~ListaEnemigos()
{
	/*for (int i = 0; i < numero; i++) {
		delete lista[i];
	}*/
}

void ListaEnemigos::CreaEnemigos(const char *fich)
{
	f = new char[strlen(fich)];
	strcpy(f, fich);
	int  i = 0;
	int x, y;	
	bool tipo=false;
	ifstream fichero(f); //"EnemigosDesdeElPrincipio.txt"
	if (!fichero)
		cout << "No se puede abrir el fichero" << endl;
	else {
		while (!fichero.eof() && i <MAX_ENEMIGOS) {
			fichero >> tipo;
			fichero >> x;
			fichero >> y;
			Vector aux(x, y);
			if(tipo==false)
			lista[i] = new Enemigo(aux);
			if(tipo == true)
			lista[i] = new EnemigoD(aux);
						i++;
			numero++;
		} 
	}
	fichero.close();
}

bool ListaEnemigos::Agregar(Enemigo * e)
{
	if (numero < MAX_ENEMIGOS) {
		lista[numero++] = e;
		if ((rand() % 2) == 0) {
			e->getVelocidad().setValor(2.0f, 0.0f);
		}
		else
			e->getVelocidad().setValor(-2.0f, 0.0f);
	}
	else {
		return false;
	}
	return true;
}

void ListaEnemigos::Dibuja()
{
	for (int i = 0; i < numero; i++) {
		lista[i]->Dibuja();
	}
}

void ListaEnemigos::Mueve(float t)
{
	for (int i = 0; i < numero; i++) {
		lista[i]->Mueve(t);
	}
}

void ListaEnemigos::Rebote() {
	for (int i = 0; i < numero; i++) {
		for (int j = i + 1; j <= numero - 1; j++) {
			Interaccion::Rebote(*(lista[i]), *(lista[j]));
		}
	}
}
void ListaEnemigos::Rebote(Personaje &p,ListaCajas c,Llave &l) {
	for (int i = 0; i < numero; i++) {
		Interaccion::Rebote(p, *(lista[i]), c,l);
	}
}
void ListaEnemigos::Rebote(Plataforma p) {
	for (int i = 0; i < numero; i++) {
		Interaccion::Contacto(*(lista[i]), p);		

	}
}

void ListaEnemigos::Rebote(Escenario e) {
	for (int i = 0; i < numero; i++) {
		Interaccion::Rebote(*(lista[i]), e);
	}
}

int ListaEnemigos::Eliminar(int ind,bool caso) //Si es matado por una caja true, si es por un personaje false
{
	int txt = 0;
	if (ind < 0 || ind >= numero) {
		return 0;
	}
	if (caso == true) {
		txt=lista[ind]->Enemigo::EnemEliminado();
	}
	else
		txt=lista[ind]->EnemEliminado();
	
	delete lista[ind];
	numero--;
	for (int i = ind; i < numero; i++) {
		lista[i] = lista[i + 1];
	}
	return txt;
}

int ListaEnemigos::Colision(Personaje p)
{
	for (int i = 0; i < numero;i++){
		if (Interaccion::Colision(*(lista[i]), p)) {
			return i;
		}
	}
	return -1;
}

void ListaEnemigos::Choque(ListaCajas c)//No funciona bien
{
	for (int i = 0; i < numero; i++) {
		if (Interaccion::Choque(c, *(lista[i]))) {
			float aux = lista[i]->getVelocidad().x;
			float aux1 = lista[i]->getVelocidad().y;
			lista[i]->getVelocidad().setValor(-aux, aux1);
		}
	}
}

void ListaEnemigos::Choque(Llave l)
{
	for (int i = 0; i < numero; i++) {
		if (Interaccion::Colision(*(lista[i]),l))
		{
			float aux = lista[i]->getVelocidad().x;
			float aux1 = lista[i]->getVelocidad().y;
			lista[i]->getVelocidad().setValor(-aux, aux1);
		}
	}
}

int ListaEnemigos::Contacto(ListaCajas c)//No funciona bien
{
	for (int i = 0; i < numero; i++) {
		if (Interaccion::Colision(*(lista[i]), c)){
			return i;
		}
	}
	return -1;
}

void ListaEnemigos::DestruirContenido()
{
	for (int i = 0; i < numero; i++) {
		delete lista[i];
	}
	numero = 0;
}

