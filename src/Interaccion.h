#pragma once
#include "Personaje.h"
#include "Plataforma.h"
class Interaccion abstract //no se si se usa as� 
{
public:
	Interaccion();
	~Interaccion();
	static bool Contacto(Movil &pers, Plataforma &p);
};

