#pragma once
#include "Vector2D.h"
#include "Tono.h"
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

