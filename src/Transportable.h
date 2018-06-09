#pragma once
#include "Movil.h"
#include "Personaje.h"
class Transportable:public Movil
{
public:
	bool trans; //Se est� transportando??
	Transportable(Vector pos, float l);
	~Transportable();
	void CambiaEstado();
	virtual void Moviendo(float x, float y, float l) {};
protected:	
	bool tocando; //Est� la caja teniendo contacto con el personaje??

};

