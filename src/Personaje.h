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
	int GetVida() {	return vida;}
	float Distancia(Vector2D centro, Vector2D *direccion);
	friend class Interaccion;
};

