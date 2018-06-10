#pragma once
#include "Personaje.h" //vidas personaje normal, mpersonaje siempre el mismo
#include "Plataforma.h"
#include "Enemigo.h"
#include "Escenario.h"
#include "Box.h"
#include "ListaCajas.h"
#include "Llave.h"
class Enemigo;
class Interaccion  
{
public:
	Interaccion();

	~Interaccion();

	static void Rebote(Movil &m, Escenario &e);

	static bool Contacto(Movil &m, Plataforma p);

	static bool Contacto(Personaje &pers, Plataforma p); //Hasta aqui son funciones con polimorfismo
		

	static bool Contacto(Movil &m, Box c);
	static void Rebote(Enemigo &e, Enemigo &e1);
	static bool Colision(Enemigo e, Personaje p);

	static void Contacto(Enemigo &e, ListaCajas c);		//Juntar											  
	static bool Choque(ListaCajas c, Enemigo &e);
	static bool Colision(Enemigo &e, ListaCajas c);
	

	static void Rebote(Personaje &p, Enemigo &e,ListaCajas c,Llave &llave);

	

	static void Coger(Personaje &p, Transportable &c);

	static void Mover(Personaje &p, Transportable &c);



	static void Mover(Transportable &c, Transportable &c1, Personaje &p);

	
	static bool Tocando(Personaje &p, Movil &c);
	static bool ComprobarDistanciaPlataforma(Movil &m,float dif,Vector dir);
	
	

	static bool Colision(Enemigo &e, Transportable &c);

	static void EncuentroFinal(Llave &l, Escenario e);
	
};

