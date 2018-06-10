#pragma once
#include "Vector.h"
#include "Movil.h"
#include "Escenario.h"
#include "Interaccion.h"
using ETSIDI::SpriteSequence;
class Enemigo :public Movil
{
private:
	bool first_time;
	SpriteSequence en1;

public:
	Enemigo(Vector pos);
	~Enemigo();
	virtual void Dibuja();
	//void setAltura(float a);
	//void Caida(float t);
	//void Mueve(float t);
	//Vector2D& getPosicion();
	//Vector2D& getVelocidad();
	//PARA PROBAR FUNCIONAMIENTO
	virtual int EnemEliminado();
	void Rebote_escenario(float &posOJO, float xmax, float xmin);
	float Rebote_plat(float dis, float xmax, float xmin);
	friend class Interaccion;
};

