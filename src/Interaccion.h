#pragma once
#include "Personaje.h"
#include "Plataforma.h"
class Interaccion abstract //no se si se usa as� 
{
public:
	Interaccion();
	~Interaccion();
	static void Contacto(Movil &pers, Plataforma &p);
};

