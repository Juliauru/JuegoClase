#pragma once
#include "Movil.h"
class Personaje:public Movil
{
private:
	float altura;
	float posinicial;
	float vinicial;
public:
	void Dibuja();
	Personaje(float a=1);
	~Personaje();	
	void Mueve(float t,bool p=false);
	void Salto();
	/*friend class Interaccion;*/
};

