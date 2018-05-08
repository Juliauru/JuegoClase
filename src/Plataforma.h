#pragma once
#include "Movil.h"
#include "Pared.h"
class Plataforma:public Movil
{
protected:
	Pared bases[2];
	static 	int n_plataformas;
	int ancho;
	int largo;
	float lado;
public:
	Plataforma(int l=2);
	virtual ~Plataforma();
	void Dibuja();
	static int get_nplataformas();
	void setLargo(int l = 2);
	float Distancia(Vector2D centro, Vector2D* direccion);
	
};


