#include "Movil.h"



Movil::Movil()
{
}


Movil::~Movil()
{
}
void Movil::Mover() {
	//ecuaciones físicas
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
