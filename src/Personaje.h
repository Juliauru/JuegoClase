#pragma once
#define POTENCIA_SALTO 8.0f
#include "Movil.h"
#include "Escenario.h"
class Personaje:public Movil
{
private:
	//Longitud característica radio esfera, hasta que tengamos una altura, luego cambiar
	int vida;
public:
	Personaje(float a=0.5);
	~Personaje();	
	void Dibuja();
	void DibujaVidas(float y,float inc);
	void Salto();
	int GetVida() {	return vida;}
	float Distancia(Vector2D centro, Vector2D *direccion);
	friend class Interaccion;
};

