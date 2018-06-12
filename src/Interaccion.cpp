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
bool Interaccion::Contacto(Personaje &pers, Plataforma p) {  //Función que relaciona el choque del personaje con la plataforma, no se utliza polimorfismo en su interior, por que depende de las dimensiones de lo que lleve
	//Esto se muestra en el bool transportando
	Vector dir;
	float dis = p.Distancia(pers.posicion, &dir);
	float dif;
	if (pers.transportando == false) {
		dif = dis - pers.Long_caracteristica;
	}
	if (pers.transportando == true) {
		if (pers.velocidad.y <= 0)
			dif = dis - pers.Long_caracteristica;
			
		if (pers.velocidad.y > 0) {
			Vector aux;
			aux.setValor(pers.posicion.x, pers.posicion.y + 2 * TAMANIO);
			dif = p.Distancia(aux, &dir) - pers.Long_caracteristica;
		}
	}
	return(Interaccion::ComprobarDistanciaPlataforma(pers, dif, dir));
	}
bool Interaccion::Contacto(Movil &m, Plataforma p) { //Comprobación de si un objeto móvil está tocando o no a una plataforma y actuación en consecuencia
	Movil *mov = &m;
	Vector dir;
	float dif;
	float dis = p.Distancia(m.posicion, &dir);
	float xmin = ((float)p.posicion.x) + 0.01f;
	float xmax = ((float)p.limite.x)-0.01f;
	dif=mov->Rebote_plat(dis, xmax, xmin);
	return(Interaccion::ComprobarDistanciaPlataforma(m,dif, dir));
}

bool Interaccion::Contacto(Movil &m, Box c) { //Comprobación de si un objeto móvil está tocando o no una caja
	Plataforma p((c.getPosicion().x - (c.Long_caracteristica)), (c.getPosicion().y + (c.Long_caracteristica)), (c.getPosicion().x + (c.Long_caracteristica)), (c.getPosicion().y + (c.Long_caracteristica)));
	Vector dir;
	float dif = p.Distancia(m.posicion, &dir) - m.Long_caracteristica;
	return(Interaccion::ComprobarDistanciaPlataforma(m,dif, dir));
}

void Interaccion::Contacto(Enemigo &e, ListaCajas c) { //Comprueba si un enemigo se está tocando con alguna de las cajas del nivel
	for (int i = 0; i < c.n_cajas; i++) {
		Interaccion::Contacto(e, *c.lista[i]);
	}
}



void Interaccion::Rebote(Enemigo & e, Enemigo & e1) //Resolución del encuentro entre dos enemigos
{
	if (e.posicion.y == e1.posicion.y) {
		Vector dir;
		float dist = e.Distancia(e1.posicion,&dir);
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
				
			}
		}

	}
}
void Interaccion::Rebote(Personaje  &p, Enemigo &e,ListaCajas c,Llave &llave) //Muerte del personaje, dejando lo que se transporte en la posicion que estaba y restando una vida 
{
	if ((p.posicion.x + (p.Long_caracteristica) > e.posicion.x - e.Long_caracteristica) && (p.posicion.y - (p.Long_caracteristica) >= e.posicion.y - e.Long_caracteristica) && (p.posicion.y - (p.Long_caracteristica) < e.posicion.y) && (p.posicion.x - (p.Long_caracteristica) < e.posicion.x + e.Long_caracteristica)) {
		c.Coger(p);
		p.transportando = false;
		llave.trans = false;	
	p.vida -= 1;
	p.posicion.x = p.Long_caracteristica;
	p.posicion.y = 2.5f;
	}
}

void Interaccion::Rebote(Movil &m, Escenario &e) //Rebote de cualquier objeto con el escenario (limites del juego)
{
	Movil *mov=&m;
	float xmin = e.limites[3].posicion.x+ m.Long_caracteristica;
	float xmax = e.limites[3].limite.x- m.Long_caracteristica;
	mov->Rebote_escenario(e.p_ojo_y, xmax, xmin);	
}

void Interaccion::Mover(Personaje &p, Transportable &c) { //Movimiento de una caja o llave con el personaje cuando se está transportando
	Transportable *punt=&c;
	Vector dir;
	float dist = p.Distancia(c.posicion, &dir);	
	float r = p.Long_caracteristica + c.Long_caracteristica;
	
	if (c.trans == false) {
		if (r >= dist && fabsf(p.posicion.y-c.posicion.y)<0.1) {
			punt->Moviendo(p.posicion.x, p.posicion.y, p.Long_caracteristica);
		}
	}
	if (c.trans == true) {
		c.posicion.x = p.posicion.x;
		c.posicion.y = p.posicion.y + p.Long_caracteristica + c.Long_caracteristica;

	}
}

void Interaccion::Mover(Transportable &caja1, Transportable &caja2, Personaje &p) //Movimiento consecutivo de dos cajas al estar en contacto y ser una de ellas empujada por el personaje
{
	bool t = Tocando(p, caja1);
	bool s = Tocando(p, caja2);
	Transportable& c1 = caja2;
	Transportable& c = caja1;
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
bool Interaccion::Colision(Enemigo e, Personaje p) //Si el personaje salta sobre el enemigo suma puntuación y además devuelve un true para poder utilizar en una función para eliminar el enemigo
{
	if (p.posicion.x <= (e.posicion.x + p.Long_caracteristica) && p.posicion.x >= (e.posicion.x - p.Long_caracteristica) && p.posicion.y <= (e.posicion.y + e.Long_caracteristica + p.Long_caracteristica)&& p.posicion.y > (e.posicion.y + e.Long_caracteristica + p.Long_caracteristica/2)) {
		Personaje::SetPuntuacion(100, 0);
		return true;
	}
	return false;
}

bool Interaccion::Choque(ListaCajas c, Enemigo &e) // Evita que los enemigos se queden atrapados dentro de las cajas
{
	for (int i = 0; i < c.n_cajas; i++) {
		float dist = fabsf(c.lista[i]->posicion.x - e.posicion.x);
		float r = c.lista[i]->Long_caracteristica + e.Long_caracteristica;
		if (fabsf(c.lista[i]->posicion.y - e.posicion.y) < 0.5 && r >= dist) {
			return true;
		}
	}
	return false;
}

void Interaccion::Coger(Personaje &p, Transportable &c) { //Realiza la acción de coger un objeto movil transportable
	bool t = Tocando(p, c);
	if (t == true && fabsf(p.velocidad.y)<0.02f) {
		c.CambiaEstado();
		p.CambiaEstado();
		if (c.trans == false) {
			c.posicion.x = p.posicion.x + p.Long_caracteristica + c.Long_caracteristica;
		}
	}
}

bool Interaccion::Tocando(Personaje &p, Movil &m) {  //Devuelve si existe contacto entre un personaje y cualquier otro objeto movil
	Vector dir;
	float dist = p.Distancia(m.posicion, &dir);
	float r = p.Long_caracteristica + m.Long_caracteristica;
	if (r >= dist)
		return true;
	return false;
}
bool Interaccion::ComprobarDistanciaPlataforma(Movil &m,float dif,Vector dir) { //Distancia
	if (dif <= 0.0f) {
		if (m.velocidad.y <= 0) {
			m.velocidad.y = 0;
		}
		m.vinicial = 0;
		m.posinicial = 0;
		Vector v_inicial = m.velocidad;
		m.velocidad = v_inicial - dir * 2.0*(v_inicial*dir);
		m.posicion = m.posicion - dir * dif;

		return true;
	}
	return false;
}
bool Interaccion::Colision(Enemigo &e, Transportable &c) // Evita que los enemigos se queden atrapados dentro de las cajas
{
	float dist;
	float r;
	Vector aux;
		dist = e.Distancia(c.posicion, &aux);
		r = e.Long_caracteristica + c.Long_caracteristica;
		
		if (r >= dist) {
			if ((e.posicion.x <= (c.posicion.x + c.Long_caracteristica)) && (e.posicion.x >= (c.posicion.x - c.Long_caracteristica)))
			 {
				return true;
			}
		}
		return false;
	}
void Interaccion::EncuentroFinal(Llave & l, Escenario e) //Fin del nivel, cuando la llave está en la puerta
{
	if (l.posicion.x<e.puerta.x + 0.5 && l.posicion.x>e.puerta.x - 0.5&&l.posicion.y >= e.puerta.y&&l.posicion.y < e.puerta.y+1.5){
		l.num = 0;
}
}

bool Interaccion::Colision(Enemigo &e, ListaCajas c) {
	for (int i = 0; i < c.n_cajas; i++) {
		if (Interaccion::Colision(e, *c.lista[i]))
			return true;
	}
	return false;
}




