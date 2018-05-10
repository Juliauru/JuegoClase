#include "Movil.h"



Movil::Movil()
{
}


Movil::~Movil()
{
}
void Movil::Mueve(float t) {
	velocidad = velocidad + (0.5*aceleracion.y*t*t);
	posicion = posicion + velocidad*t;
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
