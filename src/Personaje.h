#pragma once
#include "Movil.h"
class Personaje:public Movil
{
private:
	//Longitud característica radio esfera, hasta que tengamos una altura, luego cambiar
	static int vida;
public:
	void Dibuja();
	Personaje(float a=1);
	~Personaje();	
	void Salto();
	static int GetVida() {
		return vida;
	}
	friend class Interaccion;
};

