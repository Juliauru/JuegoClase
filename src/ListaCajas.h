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

	void Coger(Personaje &pers);

	void Contacto(Personaje &pers);

	void Mover(Personaje &pers);
	
	friend class Interaccion;

	//PRUEBA
	//void Mover();

};

