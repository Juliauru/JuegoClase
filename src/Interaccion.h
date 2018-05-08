#pragma once
#include "Personaje.h"
#include "Plataforma.h"
class Interaccion abstract //no se si se usa así 
{
public:
	Interaccion();
	~Interaccion();
	static void Contacto(Movil &pers, Plataforma &p);
};

