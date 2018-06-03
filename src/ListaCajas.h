#pragma once
#include "Box.h"
#include "Personaje.h"
class ListaCajas:public Box
{
private:
	char *f;
	int n_cajas;
	Box *lista[CAJASMAX];
public:
	ListaCajas();
	~ListaCajas();

	void Set_ncajas(int num);

	void CreaCajas(const char *fich);

	void Dibuja();

	void Mueve(float t);

	void Coger(Personaje &pers);

	void Contacto(Personaje &pers);

	void Mover(Personaje &pers);

	void Caida(Plataforma p);
	
	friend class Interaccion;

	};

