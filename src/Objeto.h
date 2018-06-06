#pragma once
#include "Vector.h"
#include "Tono.h"
class Objeto
{
protected:
	Vector posicion;
	Tono color;
	Objeto(Vector v);
	~Objeto();
public:
	Vector & getPosicion();
	Tono& getColor();
	void SetPosicion(float x, float y);
};

