#pragma once
#include "ETSIDI.h"
#include "Transportable.h"
using  ETSIDI::Sprite;
class Llave:public Transportable
{
	//PRUEBA A PUBLIC,ESTABA EN PRIVATE
private:
	Sprite sprite;
	int num;
public:
	Llave(Vector pos);
	Llave();
	~Llave();
	void Dibuja();
	void InicioValor();
	int ValorLlave() { return num; }
	void Moviendo(float x,float y,float l);
	friend class Interaccion;
};

