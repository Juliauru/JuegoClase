#pragma once
#include "Personaje.h" //vidas personaje normal, mpersonaje siempre el mismo
#include "Plataforma.h"
#include "Enemigo.h"
#include "Escenario.h"
#include "Box.h"
#include "ListaCajas.h"
class Enemigo;
class Interaccion //abstract //no se si se usa así 
{
public:
	Interaccion();
	~Interaccion();
	static bool Contacto(Personaje &m, Plataforma &p);
	static bool Contacto(Movil &m, Plataforma &p);

	static void Contacto(Movil &m, Box &c);//La referencia en la caja maybe sobra
	static void Contacto(Enemigo &e, ListaCajas c);//Solucion provisional, luego habrá que eliminarlo 

	static bool Contacto(Enemigo &enem, Plataforma &p);//BOOL CAMBIADO POR PAULA
													   //Solucion provisional, luego habrá que eliminarlo 

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
};

