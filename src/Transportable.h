#pragma once
#include "Movil.h"
class Transportable:public Movil
{
public:
	bool trans; //Se est� transportando??
	Transportable(Vector pos, float l);
	~Transportable();
	void CambiaEstado();
protected:	
	bool tocando; //Est� la caja teniendo contacto con el personaje??

};

