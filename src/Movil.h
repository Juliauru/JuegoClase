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
	Movil(Vector pos, Vector vel=0, Vector ac=0, float l=0);
	~Movil();
public:	
	void virtual Mueve(float t);
	void SetVel(float vx, float vy);
	Vector& getVelocidad();
	Vector& getAceleracion();
	float get_LCaract();
	float Distancia(Vector centro, Vector *direccion);
	virtual void Rebote_escenario(float &posOJO,float xmax,float xmin);
	virtual float Rebote_plat(float dir, float xmax, float xmin);
	friend class Interaccion;
};

