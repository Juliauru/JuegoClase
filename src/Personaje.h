#pragma once
#include "Movil.h"
class Personaje:public Movil
{
private:
	//Longitud característica radio esfera, hasta que tengamos una altura, luego cambiar
	int vida;
public:
	void Dibuja();
	Personaje(float a=0.5);
	~Personaje();	
	void Salto();
	int GetVida() {
		return vida;
	}
	friend class Interaccion;
};

