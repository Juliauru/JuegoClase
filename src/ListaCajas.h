#pragma once
#include "Box.h"
#include "Personaje.h"
#include "Llave.h"
class ListaCajas:public Box
{
private:
	char *f; //Fichero desde el que se leen las posiciones iniciales
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

	void Mover(Personaje &pers,Llave &llave);

	void DestruirContenido();

	void Caida(Plataforma p);

	void Rebote(Escenario e);
	
	friend class Interaccion;

	};

