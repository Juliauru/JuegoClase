#pragma once
#include "Transportable.h"
#include "Personaje.h"
class Box:public Transportable
{
protected:
	bool tocando; //Est� la caja teniendo contacto con el personaje??
public:
	Box();
	~Box();
	void Dibuja();
	void CambiaEstado();
};

