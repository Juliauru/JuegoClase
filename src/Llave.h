#pragma once
#include "ETSIDI.h"
#include "Transportable.h"
using  ETSIDI::Sprite;
class Llave:public Transportable
{
	//PRUEBA A PUBLIC,ESTABA EN PRIVATE
private:
	Sprite sprite;
public:
	int num;
public:
	Llave(Vector pos);
	Llave();
	~Llave();
	void Dibuja();
	int ValorLlave() { return num; }
	void Moviendo(float x,float y,float l);
};

