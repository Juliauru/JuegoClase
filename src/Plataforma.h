#pragma once
#include "Movil.h"
#include "Pared.h" 
class Plataforma :public Pared //Cambiar a paredes
{
protected:
	static int n_plataformas;
public:
	Plataforma(Vector pos,int l = 2);
	Plataforma(float v1x, float v1y, float v2x, float v2y);
	Plataforma();
	virtual ~Plataforma();
	static int get_nplataformas();
	static void set_nplataformas(int n);
	void setLargo(int l = 2);
	void Dibuja();
};



