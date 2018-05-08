#pragma once
#include "Plataforma.h"
#include "Pared.h"
class Escenario
{
public:
	Vector2D vertices[4];
	Plataforma* plat;
	Pared base;
	Pared limites[4];
	Plataforma p_inicio;
	//Pared* bases;
public:
	void Dibuja();
	void Reorientar();
	Escenario();
	~Escenario();
};

