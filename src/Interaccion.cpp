#include "Interaccion.h"



Interaccion::Interaccion()
{
}


Interaccion::~Interaccion()
{
}
bool Interaccion::Contacto(Movil &m, Plataforma &p) {
	Vector2D dir;
	float dif = p.Distancia(m.posicion, &dir) - m.Long_caracteristica-0.25/2;
	if (dif <= 0.0f)
	{		
			Vector2D v_inicial = m.velocidad;
			m.velocidad = v_inicial - dir * 2.0*(v_inicial*dir);
			m.posicion = m.posicion - dir * dif;
		
		return true;
	}
	return false;
}

