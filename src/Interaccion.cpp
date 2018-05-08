#include "Interaccion.h"



Interaccion::Interaccion()
{
}


Interaccion::~Interaccion()
{
}
void Interaccion::Contacto(Movil &m, Plataforma &p) {
	Vector2D dir;
	float dif = p.Distancia(m.posicion, &dir) - m.Long_caracteristica;
	if (dif <= 0.0f)
	{
		if (m.velocidad.y > 0) {
			Vector2D v_inicial = m.velocidad;
			m.velocidad = v_inicial - dir * 2.0*(v_inicial*dir);
			m.posicion = m.posicion - dir * dif;
		}
		else {
			m.velocidad.y = 0;
		}
		//return true;
	}
	//return false;
}

