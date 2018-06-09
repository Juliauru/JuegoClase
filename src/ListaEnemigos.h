#pragma once
#include "Enemigo.h"
#include "Pared.h"
#include "Interaccion.h"
#include "Personaje.h"
#include "ListaCajas.h"
#include "Movil.h"
#include "Constantes.h"
#include "Llave.h"
class ListaEnemigos :public Enemigo
{
private:
	char *f;
	Enemigo *lista[MAX_ENEMIGOS];
	int numero;

public:
	ListaEnemigos();
	~ListaEnemigos();

	void CreaEnemigos(const char *fich);

	bool Agregar(Enemigo *e);

	void Dibuja();

	void Mueve(float);

	void Rebote();

	void Rebote(Personaje & p,ListaCajas c,Llave &l);

	void Rebote(Plataforma p);

	void Rebote(Escenario e);

	int Eliminar(int ind, bool caso=false);

	int Colision(Personaje p);

	void Choque(ListaCajas c);
	
	void Choque(Llave l);

	int Contacto(ListaCajas c);
	
	void DestruirContenido();

	void DibujaFrase(int num, float y, float inc);

	friend class Interaccion;
};

