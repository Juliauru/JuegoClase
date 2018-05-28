#include "Interaccion.h"
#include "Constantes.h"
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;
Interaccion::Interaccion()
{
}
Interaccion::~Interaccion()
{
}
bool Interaccion::Contacto(Personaje &pers, Plataforma p) { 
	Vector2D dir;
	float dif;
	if (pers.transportando == false) {
		dif = p.Distancia(pers.posicion, &dir) - pers.Long_caracteristica;
	}
	if (pers.transportando == true) {
		if (pers.velocidad.y <= 0)
			dif = p.Distancia(pers.posicion, &dir) - pers.Long_caracteristica;
			
		if (pers.velocidad.y > 0) {
			Vector2D aux;
			aux.setValor(pers.posicion.x, pers.posicion.y + 2 * TAMANIO);
			dif = p.Distancia(aux, &dir) - pers.Long_caracteristica;
			
		}
	}
	return(Interaccion::ComprobarDistanciaPlataforma(pers, p, dif, dir));
	}
bool Interaccion::Contacto(Enemigo &ene, Plataforma p) { //arreglar con polimorfismo creo 
	Vector2D dir;
	float dif = p.Distancia(ene.posicion, &dir) - ene.Long_caracteristica;
	if (dif <= 0.0f)
	{
		//cout << "OK" << endl;
		float xmin = p.posicion.x+0.01;
		float xmax = p.limite.x-0.01;
		if (ene.posicion.x >= xmax) ene.velocidad.x = -ene.velocidad.x;
		if (ene.posicion.x <= xmin) ene.velocidad.x = -ene.velocidad.x;
	}
	return(Interaccion::ComprobarDistanciaPlataforma(ene, p, dif, dir));
	}

bool Interaccion::Contacto(Movil &m, Plataforma p) { //Creo que no es necesario
	Vector2D dir;
	float dif = p.Distancia(m.posicion, &dir) - m.Long_caracteristica;
	return(Interaccion::ComprobarDistanciaPlataforma(m, p, dif, dir));
}
bool Interaccion::Contacto(Movil &m, Box c) {
	Plataforma p((c.getPosicion().x - (c.Long_caracteristica)), (c.getPosicion().y + (c.Long_caracteristica)), (c.getPosicion().x + (c.Long_caracteristica)), (c.getPosicion().y + (c.Long_caracteristica)));
	//p.setLimites((c.getPosicion().x - (c.Long_caracteristica)), (c.getPosicion().y + (c.Long_caracteristica)), (c.getPosicion().x + (c.Long_caracteristica)), (c.getPosicion().y + (c.Long_caracteristica)));
	Vector2D dir;
	float dif = p.Distancia(m.posicion, &dir) - m.Long_caracteristica;
	return(Interaccion::ComprobarDistanciaPlataforma(m, p, dif, dir));
}
void Interaccion::Contacto(Enemigo &e, ListaCajas c) {
	for (int i = 0; i < c.n_cajas; i++) {
		Plataforma p((c.lista[i]->posicion.x - (c.lista[i]->Long_caracteristica)), (c.lista[i]->posicion.y + (c.lista[i]->Long_caracteristica)), (c.lista[i]->posicion.x + (c.Long_caracteristica)), (c.lista[i]->posicion.y + (c.lista[i]->Long_caracteristica)));
		//p.setLimites((c.lista[i]->posicion.x - (c.lista[i]->Long_caracteristica)), (c.lista[i]->posicion.y + (c.lista[i]->Long_caracteristica)), (c.lista[i].posicion.x + (c.Long_caracteristica)), (c.lista[i].posicion.y + (c.lista[i].Long_caracteristica)));
		Vector2D dir;
		float dif = p.Distancia(e.posicion, &dir) - e.Long_caracteristica;
	    Interaccion::ComprobarDistanciaPlataforma(e, p, dif, dir);
	}
}



void Interaccion::Rebote(Enemigo & e, Enemigo & e1) //Intentos fallidos
{
	/*if (e.posicion.x == e1.posicion.x && e.posicion.y == e1.posicion.y) {
		e.velocidad.x = -e.velocidad.x;
		e1.velocidad.x = -e1.velocidad.x;
	}*/
	if (e.posicion.y == e1.posicion.y) {
		Vector2D dir;
		//float dist = fabsf(e.posicion.x - e1.posicion.x);+
		float dist = e.Distancia(e1.posicion,&dir);
		//if (dist == 0)dist = 0.0001f; intento para que se separaran las que vibran, but no
		float r = e.Long_caracteristica + e1.Long_caracteristica;
		if (dist<=r) {
			if (dist > e.Long_caracteristica*1.5) {
				e.velocidad.x = -e.velocidad.x;
				e1.velocidad.x = -e1.velocidad.x;
				if (e.velocidad.x == 0 && e1.velocidad.x < 0)
					e.velocidad.x = 2.0f;
				else if(e1.velocidad.x > 0)
					e.velocidad.x = -2.0f;
				if (e1.velocidad.x == 0 && e.velocidad.x < 0)
					e1.velocidad.x = 2.0f;
				else if (e.velocidad.x > 0)
					e1.velocidad.x = -2.0f;
				
			}
			else {
				/*if (e.velocidad.x < 0)
					e.velocidad.x =  2.5;
				else
					e.velocidad.x = - 2.5;
				if (e1.velocidad.x < 0)
					e1.velocidad.x = ;
				else
					e1.velocidad.x = - 4;*/
				if (e.velocidad.x < 0) {
					e.posicion.x = e.posicion.x + e.Long_caracteristica * 2;
					e.velocidad.x = 2.0f;
					e1.velocidad.x = -2.0f;
				}

				else if (e.velocidad.x > 0) {
					e.posicion = e.posicion.x - e.Long_caracteristica * 2;
					e1.velocidad.x = 2.0f;
					e.velocidad.x = -2.0f;
				}
				/*if (e1.velocidad.x < 0)

					e1.posicion.x = e1.posicion.x + e.Long_caracteristica;
				else if (e1.velocidad.x > 0)
					e1.posicion.x = e1.posicion.x - e.Long_caracteristica;*/
			}
		}

	}
}

void Interaccion::Rebote(Personaje  &p, Enemigo &e)
{
	//bool t=Interaccion::Tocando(p, e);
	if ((p.posicion.x + (p.Long_caracteristica) > e.posicion.x - e.Long_caracteristica) && (p.posicion.y - (p.Long_caracteristica) >= e.posicion.y - e.Long_caracteristica) && (p.posicion.y - (p.Long_caracteristica) < e.posicion.y) && (p.posicion.x - (p.Long_caracteristica) < e.posicion.x + e.Long_caracteristica)) {
		
	p.vida -= 1;
		p.posicion.x = p.Long_caracteristica;
		p.posicion.y = p.Long_caracteristica;
	}
}

void Interaccion::Rebote(Movil &m, Escenario &e) //Intentar hacer poco a poco, no se como quedará
{
	float xmin = e.limites[3].posicion.x;
	float xmax = e.limites[3].limite.x;
	if (m.posicion.x >= xmax) m.posicion.x = xmax;
	if (m.posicion.x <= xmin) m.posicion.x = xmin;
	if (m.posicion.y > (8+ e.p_ojo_y))
		e.p_ojo_y = e.p_ojo_y+8; /// (JULIA LEEME :) -> Si se cambia el 8 hay que cambiarlo tambien en el metodo dibuja vidas de personaje <-
	if (m.posicion.y <(e.p_ojo_y-8))
		e.p_ojo_y = e.p_ojo_y -8;
}
void Interaccion::Rebote(Enemigo &ene, Escenario e) {
	float xmin = e.limites[3].posicion.x; 
	float xmax = e.limites[3].limite.x;
	if (ene.posicion.x >= xmax) ene.velocidad.x = -ene.velocidad.x;
	if (ene.posicion.x <= xmin) ene.velocidad.x = -ene.velocidad.x;
}
void Interaccion::Mover(Personaje &p, Box &c) { 
	Vector2D dir;
	float dist = p.Distancia(c.posicion, &dir);	
	float r = p.Long_caracteristica + c.Long_caracteristica;
	
	if (c.trans == false) {
		if (r >= dist && fabsf(p.posicion.y-c.posicion.y)<0.1) {
			p.velocidad.x = 0;
			if (c.posicion.x > p.posicion.x) {
				c.posicion.x = p.posicion.x + p.Long_caracteristica + c.Long_caracteristica;
				c.posicion.y = p.posicion.y;
			}
			else {
				c.posicion.x = p.posicion.x - p.Long_caracteristica - c.Long_caracteristica;
				c.posicion.y = p.posicion.y;
			}
		}
	}
		if (c.trans == true) {
			c.posicion.x = p.posicion.x;
			c.posicion.y = p.posicion.y + p.Long_caracteristica + c.Long_caracteristica;

		}
	}

void Interaccion::Mover(Box &caja1, Box &caja2, Personaje &p) //Se han quitado los /2, no compila por eso 
{
	bool t = Tocando(p, caja1);
	bool s = Tocando(p, caja2);
	Box& c1 = caja2;
	Box& c = caja1;
	float dist = fabsf(c.posicion.x - c1.posicion.x);
	float r = c.Long_caracteristica + c1.Long_caracteristica;

	if (c1.trans == false && c.trans == false) {
		if (dist <= r && t && fabsf(c.posicion.y - c1.posicion.y) < 0.1) {

			if (c1.posicion.x > c.posicion.x) {
				c1.posicion.x = c.posicion.x + c.Long_caracteristica + c1.Long_caracteristica;
				c1.posicion.y = c.posicion.y;
			}
			else {
				c1.posicion.x = c.posicion.x - c.Long_caracteristica - c1.Long_caracteristica;
				c1.posicion.y = c.posicion.y;
			}
		}
		if (dist <= r && s && fabsf(c.posicion.y - c1.posicion.y) < 0.1) {

			if (c.posicion.x > c1.posicion.x) {
				c.posicion.x = c1.posicion.x + c.Long_caracteristica + c1.Long_caracteristica;
				c.posicion.y = c1.posicion.y;
			}
			else {
				c.posicion.x = c1.posicion.x - c.Long_caracteristica - c1.Long_caracteristica;
				c.posicion.y = c1.posicion.y;
			}
		}
	}
}
bool Interaccion::Colision(Enemigo e, Personaje p)
{
	if (p.posicion.x <= (e.posicion.x + p.Long_caracteristica) && p.posicion.x >= (e.posicion.x - p.Long_caracteristica) && p.posicion.y <= (e.posicion.y + e.Long_caracteristica + p.Long_caracteristica)&& p.posicion.y > (e.posicion.y + e.Long_caracteristica + p.Long_caracteristica/2)) {
		return true;
	}
	return false;
}

bool Interaccion::Choque(ListaCajas c, Enemigo & e)
{
	for (int i = 0; i < c.n_cajas; i++) {
		float dist = fabsf(c.lista[i]->posicion.x - e.posicion.x);
		float r = c.lista[i]->Long_caracteristica/*HE quitado aqui un entre 2*/ + e.Long_caracteristica;
		if (fabsf(c.lista[i]->posicion.y - e.posicion.y) < 0.5 && r >= dist) {
			return true;
		}
	}
	return false;
}

void Interaccion::Coger(Personaje &p, Box &c) {
	bool t = Tocando(p, c);
	if (t == true && fabsf(p.velocidad.y)==0) {
		c.CambiaEstado();
		p.CambiaEstado();
		if (c.trans == false) {
			c.posicion.x = p.posicion.x + p.Long_caracteristica + c.Long_caracteristica;
		}
	}
}

bool Interaccion::Tocando(Personaje &p, Movil &m) { 
	Vector2D dir;
	float dist = p.Distancia(m.posicion, &dir);
	float r = p.Long_caracteristica + m.Long_caracteristica;
	if (r >= dist)
		return true;
	return false;
}
bool Interaccion::ComprobarDistanciaPlataforma(Movil &m, Plataforma p,float dif,Vector2D dir) {
	if (dif <= 0.0f) {
		if (m.velocidad.y <= 0) {
			m.velocidad.y = 0;
		}
		m.vinicial = 0;
		m.posinicial = 0;
		Vector2D v_inicial = m.velocidad;
		m.velocidad = v_inicial - dir * 2.0*(v_inicial*dir);
		m.posicion = m.posicion - dir * dif;

		return true;
	}

	return false;
}
bool Interaccion::Colision(Enemigo e, ListaCajas c)
{
	for (int i = 0; i < c.n_cajas; i++) {
		if (e.posicion.x <= (c.posicion.x + c.Long_caracteristica + e.Long_caracteristica / 2) && e.posicion.x <= (c.posicion.x - c.Long_caracteristica - e.Long_caracteristica / 2) && c.posicion.y <= (e.posicion.y + e.Long_caracteristica) && c.posicion.y >(e.posicion.y - e.Long_caracteristica)) {
			cout << "okreturn" << endl;
			return true;
		}
		return false;
	}
}

	



