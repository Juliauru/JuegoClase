#pragma once
#include "Movil.h"
#include "Escenario.h"
#include "Constantes.h"
class Personaje:public Movil
{
private:
	//Longitud característica radio esfera, hasta que tengamos una altura, luego cambiar
	int vida;
	
public:
	bool transportando;
	Personaje(float a=TAMANIO);
	~Personaje();	
	void Dibuja();
	void DibujaVidas(float y,float inc);
	void Salto();
	int GetVida() {	return vida;}
	float Distancia(Vector2D centro, Vector2D *direccion);
	void CambiaEstado();
	friend class Interaccion;
};

