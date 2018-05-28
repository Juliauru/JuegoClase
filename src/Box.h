#pragma once
#include "Transportable.h"
#include "Personaje.h"
class Box:public Transportable
{
protected:
	bool tocando; //Est� la caja teniendo contacto con el personaje??
public:
	Box(Vector2D pos);
	~Box();
	void Dibuja();
	void CambiaEstado();
};

