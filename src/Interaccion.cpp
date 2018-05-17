#include "Interaccion.h"
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
bool Interaccion::Contacto(Movil &m, Plataforma &p) {
	Vector2D dir;
	float dif = p.Distancia(m.posicion, &dir) - m.Long_caracteristica;
	if (dif <= 0.0f)
	{
		if (m.velocidad.y <= 0)
			m.velocidad.y = 0;
		m.vinicial = 0;
		m.posinicial = 0;
		Vector2D v_inicial = m.velocidad;
		m.velocidad = v_inicial - dir * 2.0*(v_inicial*dir);
		m.posicion = m.posicion - dir * dif;


		return true;
	}

	return false;
}
void Interaccion::Contacto(Movil &m, Box &c) {
	Plataforma p;
	p.setLimites((c.getPosicion().x - (c.Long_caracteristica / 2)), (c.getPosicion().y + (c.Long_caracteristica / 2)), (c.getPosicion().x + (c.Long_caracteristica / 2)), (c.getPosicion().y + (c.Long_caracteristica / 2)));
	Vector2D dir;
	float dif = p.Distancia(m.posicion, &dir) - m.Long_caracteristica;
	if (dif <= 0.0f)
	{
		if (m.velocidad.y <= 0)
			m.velocidad.y = 0;
		m.vinicial = 0;
		m.posinicial = 0;
		Vector2D v_inicial = m.velocidad;
		m.velocidad = v_inicial - dir * 2.0*(v_inicial*dir);
		m.posicion = m.posicion - dir * dif;


		//return true;
	}

	//return false;
}
void Interaccion::Contacto(Enemigo &e, ListaCajas c) {
	for (int i = 0; i < c.n_cajas; i++) {
		Plataforma p;
		p.setLimites((c.lista[i].posicion.x - (c.lista[i].Long_caracteristica / 2)), (c.lista[i].posicion.y + (c.lista[i].Long_caracteristica / 2)), (c.lista[i].posicion.x + (c.Long_caracteristica / 2)), (c.lista[i].posicion.y + (c.lista[i].Long_caracteristica / 2)));
		Vector2D dir;
		float dif = p.Distancia(e.posicion, &dir) - e.Long_caracteristica;
		if (dif <= 0.0f)
		{
			if (e.velocidad.y <= 0)
				e.velocidad.y = 0;
			e.vinicial = 0;
			e.posinicial = 0;
			Vector2D v_inicial = e.velocidad;
			e.velocidad = v_inicial - dir * 2.0*(v_inicial*dir);
			e.posicion = e.posicion - dir * dif;

			//return true;
		}

		//return false;
	}
}
bool Interaccion::Contacto(Enemigo &ene, Plataforma &p) { //arreglar con polimorfismo creo 
	Vector2D dir;
	float dif = p.Distancia(ene.posicion, &dir) - ene.Long_caracteristica;
	if (dif <= 0.0f)
	{
		float xmin = p.posicion.x;
		float xmax = p.limite.x;
		if (ene.posicion.x >= xmax) ene.velocidad.x = -ene.velocidad.x;
		if (ene.posicion.x <= xmin) ene.velocidad.x = -ene.velocidad.x;
		if (ene.velocidad.y <= 0)
			ene.velocidad.y = 0;
		ene.vinicial = 0;
		ene.posinicial = 0;
		Vector2D v_inicial = ene.velocidad;
		ene.velocidad = v_inicial - dir * 2.0*(v_inicial*dir);
		ene.posicion = ene.posicion - dir * dif;		
		return true;
	}
	
	return false;	
	}



void Interaccion::Rebote(Enemigo & e, Enemigo & e1)
{
	/*if (e.posicion.x == e1.posicion.x && e.posicion.y == e1.posicion.y) {
		e.velocidad.x = -e.velocidad.x;
		e1.velocidad.x = -e1.velocidad.x;
	}*/
	if (e.posicion.y==e1.posicion.y) {
		float dist = fabs(e.posicion.x - e1.posicion.x);
		
		//if (dist == 0)dist = 0.0001f; intento para que se separaran las que vibran, but no
		float r = e.Long_caracteristica + e1.Long_caracteristica;
		if (r >= dist) {
			if (fabsf(e.velocidad.x) >= 1.5 && fabsf(e1.velocidad.x) >= 1.5) {
				e.velocidad.x = -e.velocidad.x;
				e1.velocidad.x = -e1.velocidad.x;
			}
			else {
				if (e.velocidad.x < 0)
					e.velocidad.x =  2.5;
				else
					e.velocidad.x = - 2.5;
				if (e1.velocidad.x < 0)
					e1.velocidad.x =  2.5;
				else
					e1.velocidad.x = - 2.5;
			}
		}	

	}
}

void Interaccion::Rebote(Personaje  &p, Enemigo &e)
{
	////IDEA PARA LAS VIDAS
	////En esta función, si se produce el choque, las vidas del personaje disminuirán en 1. Por tanto, en personaje se creará una variable
	////estática que será vidas que comenzarán valiendo 3 y en está función irán disminuyendo. En la función bonus aumentarán.
	////Introduzco friend class en Personaje, tambien función getVida();
	////ya que cuando se apoyen en las plataformas tendran el mismo punto y, volver a cambiar el if()
	////Volver a cambiar ((p.posicion.x + (p.Long_caracteristica / 1.5f) > e.posicion.x) && (p.posicion.x - (p.Long_caracteristica / 1.5f) < e.posicion.x) && p.posicion.y == e.posicion.y)
	if ((p.posicion.x + (p.Long_caracteristica) > e.posicion.x - e.Long_caracteristica) && (p.posicion.y - (p.Long_caracteristica) >= e.posicion.y - e.Long_caracteristica) && (p.posicion.y - (p.Long_caracteristica) < e.posicion.y) && (p.posicion.x - (p.Long_caracteristica) < e.posicion.x + e.Long_caracteristica)) {
		p.vida -= 1;
		p.posicion.x = p.Long_caracteristica;
		p.posicion.y = p.Long_caracteristica;
	}
		//	//Esto de las velocidades es una prueba para comprobar visualmente que chocan
		//	e.velocidad.x = -e.velocidad.x;
		//	return true;
		//	//Indicaría que pierde una vida y vuelve a empezar el nivel por el que iba (si la vida es distinta de 0)
		//	//Si la vida llega a 0 el programa se acabaría y comenzaría la pantalla principal.
		//}
		//return false;
}

void Interaccion::Rebote(Movil &m, Escenario &e) //Intentar hacer poco a poco, no se como quedará
{
	float xmin = e.p_inicio.posicion.x;
	float xmax = e.p_inicio.limite.x;
	if (m.posicion.x >= xmax) m.posicion.x = xmax;
	if (m.posicion.x <= xmin) m.posicion.x = xmin;
	if (m.posicion.y > 2* e.p_ojo_y)
		e.p_ojo_y = e.p_ojo_y+7.5; //Si se cambia el 7.5 hay que cambiarlo tambien en el metodo dibuja vidas de personaje
	if (m.posicion.y <(e.p_ojo_y-7.5))
		e.p_ojo_y = e.p_ojo_y -7.5;
}
void Interaccion::Rebote(Enemigo &ene, Escenario e) {
	float xmin = e.limites[3].posicion.x; 
	float xmax = e.limites[3].limite.x;
	if (ene.posicion.x >= xmax) ene.velocidad.x = -ene.velocidad.x;
	if (ene.posicion.x <= xmin) ene.velocidad.x = -ene.velocidad.x;
}
void Interaccion::Mover(Personaje &p, Box &c) { //No funciona del todo bien faltan detalles
	Vector2D dir;
	float dist = p.Distancia(c.posicion, &dir);	
	float r = p.Long_caracteristica + c.Long_caracteristica / 2;
	
	if (c.moviendose == false) {
		if (r >= dist && fabsf(p.posicion.y-c.posicion.y)<0.1) {
			p.velocidad.x = 0;
			if (c.posicion.x > p.posicion.x) {
				c.posicion.x = p.posicion.x + p.Long_caracteristica + c.Long_caracteristica / 2;
				c.posicion.y = p.posicion.y;
			}
			else {
				c.posicion.x = p.posicion.x - p.Long_caracteristica - c.Long_caracteristica / 2;
				c.posicion.y = p.posicion.y;
			}
		}
	}
		if (c.moviendose == true) {
			c.posicion.x = p.posicion.x;
			c.posicion.y = p.posicion.y + p.Long_caracteristica + c.Long_caracteristica / 2;

		}
	}

void Interaccion::Mover(Box & c, Box & c1)
{
	Vector2D dir;
		float dist = c.posicion.x - c1.posicion.x;
		float r = c.Long_caracteristica / 2 + c1.Long_caracteristica / 2;

		if (c1.moviendose == false) {
			if (r >= dist && fabsf(c.posicion.y - c1.posicion.y) < 0.1) {
				c.velocidad.x = 0;
				if (c1.posicion.x > c.posicion.x) {
					c1.posicion.x = c.posicion.x + c.Long_caracteristica / 2 + c1.Long_caracteristica / 2;
					c1.posicion.y = c.posicion.y;
				}
				else {
					c1.posicion.x = c.posicion.x - c.Long_caracteristica / 2 - c1.Long_caracteristica / 2;
					c1.posicion.y = c.posicion.y;
				}
			}
		}
		if (c1.moviendose == true) {
			c1.posicion.x = c.posicion.x;
			c1.posicion.y = c.posicion.y + c.Long_caracteristica / 2 + c1.Long_caracteristica / 2;

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
		float dist = fabsf(c.lista[i].posicion.x - e.posicion.x);
		float r = c.lista[i].Long_caracteristica / 2 + e.Long_caracteristica;
		if (fabsf(c.lista[i].posicion.y - e.posicion.y) < 0.5 && r >= dist) {
			return true;
		}
	}
	return false;
}

void Interaccion::Coger(Personaje &p, Box &c) {
	Vector2D dir;
	float dist = p.Distancia(c.posicion, &dir);
	float r = p.Long_caracteristica + (c.Long_caracteristica / 2)+0.01;
	if (r >= dist) {
		c.CambiaEstado();
		if (c.moviendose == false) {
			if (r >= dist) {
				p.velocidad.x = 0;				
				c.posicion.x = p.posicion.x + p.Long_caracteristica + c.Long_caracteristica / 2;
				c.posicion.y = p.posicion.y;
								
			}
		}
	}
}
	

	



