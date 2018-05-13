#pragma once
#include "Transportable.h"
#include "Personaje.h"
class Box:public Transportable
{
public:
	Box();
	~Box();
	void Dibuja();
	void CambiaEstado();
	void Mueve(Personaje &pers);
};

