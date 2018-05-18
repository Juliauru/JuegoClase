#pragma once
#include "Box.h"
#include "Personaje.h"
class ListaCajas:public Box
{
private:
	int n_cajas;
	Box * lista;
public:
	ListaCajas();
	~ListaCajas();

	void Set_ncajas(int num);

	void CreaCajas();

	void Dibuja();

	void Mueve(float t);

	void Coger(Personaje &pers);

	void Contacto(Personaje &pers);

	void Mover(Personaje &pers);

	void Caida(Plataforma p);
	
	friend class Interaccion;

	};

