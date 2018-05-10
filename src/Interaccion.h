#pragma once
#include "Personaje.h"
#include "Plataforma.h"
#include "Enemigo.h"
class Enemigo;
class Interaccion //abstract //no se si se usa así 
{
public:
	Interaccion();
	~Interaccion();
	static bool Contacto(Movil &pers, Plataforma &p);//BOOL CAMBIADO POR PAULA

	static void Rebote(Enemigo &e, Enemigo &e1);

	static bool Rebote(Personaje &p, Enemigo &e);
};

