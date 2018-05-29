#pragma once
#include "Objeto.h"
#include "Vector.h"
class Movil:public Objeto
{
protected:
	Vector velocidad;
	Vector aceleracion;
	float Long_caracteristica;
	float posinicial;
	float vinicial;
	Movil(Vector pos, Vector vel, Vector ac, float l);
	~Movil();
public:	
	void virtual Mueve(float t);
	Vector& getVelocidad();
	Vector& getAceleracion();
	float get_LCaract();
	float Distancia(Vector centro, Vector *direccion);
	friend class Interaccion;
};

