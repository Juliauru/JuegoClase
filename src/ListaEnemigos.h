#pragma once
#define MAX_ENEMIGOS 15
#include "Enemigo.h"
#include "Pared.h"
#include "Interaccion.h"
#include "Personaje.h"
class ListaEnemigos:public Enemigo
{
public:
	ListaEnemigos();
	~ListaEnemigos();
	bool Agregar(Enemigo *e);
	void Dibuja();
	void Mueve(float);

	void Rebote();

	void Rebote(Personaje & p);

	void Rebote(Plataforma p);

	void Rebote(Escenario e);

	

private:
	Enemigo *lista[MAX_ENEMIGOS];
	int numero;

	friend class Interaccion;
};

