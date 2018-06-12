#pragma once
#include "Movil.h"
#include "Personaje.h"
class Transportable:public Movil
{
protected:
	bool tocando; //Est� la caja teniendo contacto con el personaje??
	bool trans; //Se est� transportando??
public:
	Transportable(Vector pos, float l);
	~Transportable();
	void CambiaEstado();
	virtual void Moviendo(float x, float y, float l)=0;
	friend class Interaccion;

};

