#include "ListaEnemigos.h"



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

bool ListaEnemigos::Agregar(Enemigo * e)
{
	if (numero < MAX_ENEMIGOS) {
		lista[numero++] = e;
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
		Interaccion::Rebote(p,*(lista[i]));
	}
}
void ListaEnemigos::Rebote(Plataforma p) {
	//Volver a hacer
	for (int i = 0; i < numero; i++) {
		if (Interaccion::Contacto(*(lista[i]), p)) {
			Vector2D pos = p.getPosicion();
			(*lista[i]).SetPos(pos.x, pos.y);
			(*lista[i]).SetVel(3.0f, 0.0f);
		}
	}
}