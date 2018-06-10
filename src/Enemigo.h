#pragma once
#include "Vector.h"
#include "Movil.h"
#include "Escenario.h"
#include "Interaccion.h"
class Enemigo :public Movil
{

public:
	Enemigo(Vector pos);
	~Enemigo();
	void Dibuja();
	//void setAltura(float a);
	//void Caida(float t);
	//void Mueve(float t);
	//Vector2D& getPosicion();
	//Vector2D& getVelocidad();
	//PARA PROBAR FUNCIONAMIENTO
	virtual int EnemEliminado();
	friend class Interaccion;
};

