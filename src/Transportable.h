#pragma once
#include "Movil.h"
class Transportable:public Movil
{
public:
	bool trans; //Se est� transportando??
	Transportable(Vector2D pos, float l);
	~Transportable();

};

