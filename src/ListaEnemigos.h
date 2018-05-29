#pragma once
#include "Enemigo.h"
#include "Pared.h"
#include "Interaccion.h"
#include "Personaje.h"
#include "ListaCajas.h"
#include "Movil.h"
#include "Constantes.h"
class ListaEnemigos :public Enemigo
{
private:
	Enemigo *lista[MAX_ENEMIGOS];
	int numero;

public:
	ListaEnemigos();
	~ListaEnemigos();

	void CreaEnemigos();

	bool Agregar(Enemigo *e);

	void Dibuja();

	void Mueve(float);

	void Rebote();

	void Rebote(Personaje & p);

	void Rebote(Plataforma p);

	void Rebote(Escenario e);

	void Eliminar(int ind, bool caso=false);

	int Colision(Personaje p);

	void Choque(ListaCajas c);

	int Contacto(ListaCajas c);

	friend class Interaccion;
};

