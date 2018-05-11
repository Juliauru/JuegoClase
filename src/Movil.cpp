#include "Movil.h"
#include <math.h>

Movil::Movil()
{
	posinicial=0;
	vinicial=0;
}

Movil::~Movil()
{
}
void Movil::Mueve(float t) {
	if(vinicial*vinicial + 2 * aceleracion.y*(posicion.y - posinicial)>0){ 
		velocidad.y = sqrt(vinicial*vinicial + 2 * aceleracion.y*(posicion.y - posinicial));
		posicion = posicion + velocidad*t;		
	}
	
	else {
		vinicial = 0;
		posinicial = 0;
		posicion = posicion + velocidad * t + aceleracion * (0.5f*t*t);
		velocidad = velocidad + aceleracion * t;
	}
}
Vector2D& Movil::getVelocidad() {
	return velocidad;
}
Vector2D& Movil::getAceleracion() {
	return aceleracion;
}
float Movil::get_LCaract() {
	return Long_caracteristica;
}
