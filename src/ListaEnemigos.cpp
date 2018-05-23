#include "ListaEnemigos.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;
ListaEnemigos::ListaEnemigos()
{
	numero = 0;
	for (int i = 0; i < MAX_ENEMIGOS; i++) {
		lista[i] = 0;
	}

}


ListaEnemigos::~ListaEnemigos()
{
}

void ListaEnemigos::CreaEnemigos()
{
	int  n,i = 0;
	float x, y;
	/*ofstream fichero("Nombre.txt");
	fichero << "Hola, mundo" << endl;
	fichero.close();*/
	ifstream fichero("Nombre.txt");
	if (!fichero)
		cout << "No se puede abrir el fichero" << endl;
	else {
		while (!fichero.eof() && i <MAX_ENEMIGOS) {
			fichero >> x;
			fichero >> y;
			lista[i] = new Enemigo;
			lista[i]->setAltura(TAMANIO / 1.5f);
			lista[i]->SetPos(x, y);//Se puede sustituir por el getpos().setpos()
			cout << (lista[i])->getPosicion().x << " " << (lista[i])->getPosicion().y << "\n";
			lista[i]->getColor().SetColor(0,40, 30);
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
			e->getVelocidad().setValor(2.0f, -2.0f);
		}
		else
			e->getVelocidad().setValor(-2.0f, -2.0f);
		e->getPosicion().setValor(rand() % 20 + 1, rand() % 40 + 1);

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
void ListaEnemigos::Rebote(Personaje &p) {
	for (int i = 0; i < numero; i++) {
		Interaccion::Rebote(p, *(lista[i]));
	}
}
void ListaEnemigos::Rebote(Plataforma p) {
	for (int i = 0; i < numero; i++) {
		/*if (Interaccion::Contacto(*(lista[i]), p)) {*/
		Interaccion::Contacto(*(lista[i]), p);		
		/*	Vector2D pos = p.getPosicion();
		(*lista[i]).SetPos(pos.x, pos.y);
		(*lista[i]).SetVel(3.0f, 0.0f);*/
	}
}

void ListaEnemigos::Rebote(Escenario e) {
	for (int i = 0; i < numero; i++) {
		Interaccion::Rebote(*(lista[i]), e);
	}
}

void ListaEnemigos::Eliminar(int ind)
{
	if (ind < 0 || ind >= numero) {
		return;
	}
	delete lista[ind];
	numero--;
	for (int i = ind; i < numero; i++) {
		lista[i] = lista[i + 1];
	}
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
void ListaEnemigos::Contacto(ListaCajas c)//No funciona bien
{
	for (int i = 0; i < numero; i++) {
		Interaccion::Contacto(*(lista[i]),c);
	}
}
