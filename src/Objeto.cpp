#include "Objeto.h"



Objeto::Objeto(Vector2D v):posicion(v){}
Objeto::~Objeto()
{
}
Vector2D& Objeto::getPosicion() {
	return posicion;
}
Tono& Objeto::getColor() {
	return color;
}