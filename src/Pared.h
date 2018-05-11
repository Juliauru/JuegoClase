#pragma once
#include "Objeto.h"
#include "Vector2D.h"
class Pared : public virtual Objeto
{
protected:
	Vector2D limite; //El primer límite es la posicion del objeto y el segundo es limite
public:
	Pared();
	~Pared();
	void Dibuja();
	Vector2D& getLimites();
	void setLimites(float v1x, float v1y, float v2x, float v2y);
	float Distancia(Vector2D punto, Vector2D *direccion = 0);
	friend class Interaccion;
};

