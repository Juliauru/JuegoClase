#pragma once
#include "Objeto.h"
#include "Vector2D.h"
class Pared : public Objeto
{
protected:
	Vector2D vertices[4];
public:
	Pared();
	~Pared();
	void Dibuja();
	void SetVertices(float v1x, float v1y, float v2x, float v2y);
};

