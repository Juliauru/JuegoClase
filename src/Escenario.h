#pragma once
#include "Plataforma.h"
#include "Pared.h"
#include "Constantes.h"
class Escenario
{
public:
	char *f;
	float p_ojo_x, p_ojo_y, p_ojo_z;
	Vector vertices[4];
	Plataforma *plat[MAX_PLATAFORMAS];
	Pared limites[4];//0, empezando por la izquierda y en sentido horario
public:
	void Dibuja();
	void Reorientar();
	void setFichero(const char* f);
	Escenario();
	~Escenario();
	friend class Interaccion;
};

