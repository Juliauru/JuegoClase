#pragma once
#include "Vector.h"
#include "Movil.h"
#include "Escenario.h"
#include "Interaccion.h"
class Enemigo :public Movil
{
//private:
	//float Long_caracteristica; //O lo de la clase movil de long_caracteristica??_P

public:
	Enemigo(Vector pos);
	~Enemigo();
	void Dibuja();
	void setAltura(float a);
	//void Caida(float t);
	//void Mueve(float t);
	//Vector2D& getPosicion();
	//Vector2D& getVelocidad();
	//PARA PROBAR FUNCIONAMIENTO
	void SetPos(float px, float py) {
		posicion.x = px;
		posicion.y = py;
	}
	void SetVel(float vx, float vy) {
		velocidad.x = vx;
		velocidad.y = vy;
	}
	virtual void EnemEliminado();
	friend class Interaccion;
};

