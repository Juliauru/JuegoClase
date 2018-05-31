#pragma once
#include "Personaje.h" //vidas personaje normal, mpersonaje siempre el mismo
#include "Plataforma.h"
#include "Enemigo.h"
#include "Escenario.h"
#include "Box.h"
#include "ListaCajas.h"
class Enemigo;
class Interaccion  
{
public:
	Interaccion();
	~Interaccion();
	static bool Contacto(Movil &m, Plataforma p);
	static bool Contacto(Personaje &pers, Plataforma p);	
	static bool Contacto(Enemigo &enem, Plataforma p);
	static bool Contacto(Movil &m, Box c);
	static void Contacto(Enemigo &e, ListaCajas c);													  

	static void Rebote(Enemigo &e, Enemigo &e1);

	static void Rebote(Personaje &p, Enemigo &e);

	static void Rebote(Movil &m, Escenario &e);

	static void Rebote(Enemigo &ene, Escenario e);

	//static void Rebote(Enemigo &ene, Plataforma &p);

	static void Coger(Personaje &p, Box &c);

	static void Mover(Personaje &p, Box &c);

	static void Mover(Box &c, Box &c1, Personaje &p);

	static bool Colision(Enemigo e, Personaje p);
	
	static bool Choque(ListaCajas c, Enemigo &e);

	static bool Tocando(Personaje &p, Movil &c);
	static bool ComprobarDistanciaPlataforma(Movil &m, Plataforma p,float dif,Vector dir);
	
	static bool Colision(Enemigo &e, ListaCajas c);
	static bool Colision(Enemigo &e, Box &c);
};

