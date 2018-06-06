#pragma once
#include "Movil.h"
class Transportable:public Movil
{
public:
	bool trans; //Se está transportando??
	Transportable(Vector pos, float l);
	~Transportable();
	void CambiaEstado();
protected:	
	bool tocando; //Está la caja teniendo contacto con el personaje??

};

