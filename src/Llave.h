#pragma once
#include "Transportable.h"
class Llave:public Transportable
{
	//PRUEBA A PUBLIC,ESTABA EN PRIVATE
//private:
public:
	int num;
public:
	Llave(Vector pos);
	Llave();
	~Llave();
	void Dibuja();
	int ValorLlave() { return num; }
};

