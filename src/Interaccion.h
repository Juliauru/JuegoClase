#pragma once
#include "Personaje.h" //vidas personaje normal, mpersonaje siempre el mismo
#include "Plataforma.h"
#include "Enemigo.h"
#include "Escenario.h"
#include "Box.h"
class Enemigo;
class Interaccion //abstract //no se si se usa así 
{
public:
	Interaccion();
	~Interaccion();
	static bool Contacto(Movil &pers, Plataforma &p);
	static bool Contacto(Enemigo &enem, Plataforma &p);//BOOL CAMBIADO POR PAULA

	static void Rebote(Enemigo &e, Enemigo &e1);

	static bool Rebote(Personaje &p, Enemigo &e);

	static void Rebote(Movil &m, Escenario &e);

	static void Rebote(Enemigo &ene, Escenario e);
	//static void Rebote(Enemigo &ene, Plataforma &p);
	static void Coger(Personaje &p, Box &c);
};

