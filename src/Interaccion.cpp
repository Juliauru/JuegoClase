#include "Interaccion.h"



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

void Interaccion::Rebote(Enemigo & e, Enemigo & e1)
{
	if (e.posicion.x == e1.posicion.x && e.posicion.y == e1.posicion.y) {
		e.velocidad.x = -e.velocidad.x;
		e1.velocidad.x = -e1.velocidad.x;
	}
}

bool Interaccion::Rebote(Personaje  &p, Enemigo &e)
{
	//IDEA PARA LAS VIDAS
	//En esta función, si se produce el choque, las vidas del personaje disminuirán en 1. Por tanto, en personaje se creará una variable
	//estática que será vidas que comenzarán valiendo 3 y en está función irán disminuyendo. En la función bonus aumentarán.
	//Introduzco friend class en Personaje, tambien función getVida();
	//ya que cuando se apoyen en las plataformas tendran el mismo punto y, volver a cambiar el if()
	//Volver a cambiar ((p.posicion.x + (p.Long_caracteristica / 1.5f) > e.posicion.x) && (p.posicion.x - (p.Long_caracteristica / 1.5f) < e.posicion.x) && p.posicion.y == e.posicion.y)
	if ((p.posicion.x + (p.Long_caracteristica / 1.5f) > e.posicion.x) && (p.posicion.y - (p.Long_caracteristica / 1.5f) < e.posicion.y) && (p.posicion.y + (p.Long_caracteristica / 1.5f) > e.posicion.y) && (p.posicion.x - (p.Long_caracteristica / 1.5f) < e.posicion.x)) {
		p.vida -= 1;
		//Esto de las velocidades es una prueba para comprobar visualmente que chocan
		e.velocidad.x = -e.velocidad.x;
		return true;
		//Indicaría que pierde una vida y vuelve a empezar el nivel por el que iba (si la vida es distinta de 0)
		//Si la vida llega a 0 el programa se acabaría y comenzaría la pantalla principal.
	}
	return false;
}

void Interaccion::Rebote(Movil & m, Escenario e)
{
	float xmin = e.limites[3].posicion.x;
	float xmax = e.limites[3].limite.x;
	if (m.posicion.x < xmax) m.posicion.x = xmax;
	if (m.posicion.x > xmin) m.posicion.x = xmin;


}
void Interaccion::Rebote(Enemigo &ene, Escenario e) {
	float xmin = e.limites[3].posicion.x;
	float xmax = e.limites[3].limite.x;
	if (ene.posicion.x < xmax) ene.velocidad.x = -ene.velocidad.x;
	if (ene.posicion.x > xmin) ene.velocidad.x = -ene.velocidad.x;
<<<<<<< HEAD
}
=======
}
>>>>>>> 3754c2bc5e77db04903937f7bf3f446fb87c2795
