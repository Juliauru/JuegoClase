#pragma once
#include "Plataforma.h"
#include "Pared.h"
class Escenario
{
public:
	Vector2D vertices[4];
	Plataforma* plat;
	Pared limites[4];//0, empezando por la izquierda y en sentido horario
	Plataforma p_inicio;
	//Pared* bases;
public:
	void Dibuja();
	void Reorientar();
	Escenario();
	~Escenario();
	friend class Interaccion;
};

