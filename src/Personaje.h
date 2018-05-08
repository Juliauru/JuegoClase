#pragma once
#include "Movil.h"
class Personaje:public Movil
{
private:
	float altura;
	float posinicial;
	float vinicial;
	float aux;
public:
	void Dibuja();
	Personaje(float a=1);
	~Personaje();	
	void Mueve(float t);
	void Salto();
	/*friend class Interaccion;*/
};

