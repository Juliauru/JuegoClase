#pragma once
#include "Objeto.h"
#include "Vector2D.h"
class Movil:public Objeto
{
protected:
	Vector2D velocidad;
	Vector2D aceleracion;
	float Long_caracteristica;
	float posinicial;
	float vinicial;
public:
	Movil();
	~Movil();
	void virtual Mueve(float t);
	Vector2D& getVelocidad();
	Vector2D& getAceleracion();
	float get_LCaract();
	friend class Interaccion;
};

