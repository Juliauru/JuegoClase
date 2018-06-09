#pragma once
#include "Transportable.h"
#include "Personaje.h"
class Box:public Transportable
{
//protected:
//	bool tocando; //Está la caja teniendo contacto con el personaje??
public:
	Box(Vector pos);
	~Box();
	void Dibuja();
	void Moviendo(float x, float y, float l);
};

