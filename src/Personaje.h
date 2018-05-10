#pragma once
#include "Movil.h"
class Personaje:public Movil
{
private:
	static int vida;
public:
	void Dibuja();
	Personaje(float a=1);
	~Personaje();	
	void Mueve(float t,bool p=false);
	void Salto();
	static int GetVida() {
		return vida;
	}
	//friend class Interaccion;
};

