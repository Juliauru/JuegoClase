#include "Objeto.h"

Objeto::Objeto(Vector v):posicion(v){}
Objeto::~Objeto()
{
}
Vector& Objeto::getPosicion() {
	return posicion;
}
Tono& Objeto::getColor() {
	return color;
}

void Objeto::SetPos(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}
