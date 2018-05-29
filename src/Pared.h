#pragma once
#include "Objeto.h"
#include "Vector.h"
class Pared : public Objeto
{
protected:
	Vector limite; //El primer límite es la posicion del objeto y el segundo es limite
public:
	Pared(Vector pos);
	Pared(float v1x, float v1y, float v2x, float v2y);
	Pared();
	~Pared();
	void Dibuja();
	Vector& getLimites();
	void setLimites(float v1x, float v1y, float v2x, float v2y);
	float Distancia(Vector punto, Vector *direccion = 0);
	friend class Interaccion;
};

