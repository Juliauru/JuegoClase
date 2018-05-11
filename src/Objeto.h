#pragma once
#include "Vector2D.h"
#include "Tono.h"
#define TAMANIO 0.5
class Objeto
{
protected:
	Vector2D posicion;
	Tono color;
	Objeto();
	~Objeto();
public:
	Vector2D & getPosicion();
	Tono& getColor();
};

