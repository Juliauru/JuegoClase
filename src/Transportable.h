#pragma once
#include "Movil.h"
#include "Personaje.h"
class Transportable:public Movil
{
public:
	bool trans; //Se está transportando??
	Transportable(Vector pos, float l);
	~Transportable();
	void CambiaEstado();
	virtual void Moviendo(float x, float y, float l) {};
protected:	
	bool tocando; //Está la caja teniendo contacto con el personaje??

};

