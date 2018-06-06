#pragma once
#include "Movil.h"
#include "Escenario.h"
#include "Constantes.h"
class Personaje:public Movil
{
private:
	//Longitud característica radio esfera, hasta que tengamos una altura, luego cambiar
	static int puntuacion;
	static int vida;
	bool transportando;	
public:	
	Personaje();
	~Personaje();	
	void Dibuja();
	void DibujaVidas(float y,float inc);
	void Salto();
	static int GetVida() {return vida;}
	static int GetPuntuacion() { return puntuacion; }
	void SetVida(int num) {vida = num;}
	void CambiaEstado();
	friend class Interaccion;
	friend class EnemigoD;
};

