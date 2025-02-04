#pragma once
#include "Movil.h"
#include "Escenario.h"
#include "Constantes.h"
#include "ETSIDI.h"
using ETSIDI::Sprite;
class Personaje :public Movil
{
private:
	Sprite * sVida[3];
	//Longitud caracterÝstica radio esfera, hasta que tengamos una altura, luego cambiar
	static int puntuacion;
	static int vida;
	bool transportando;
	ETSIDI::SpriteSequence pers;
public:
	Personaje();
	~Personaje();
	void Dibuja();
	void DibujaVidas(float y, float inc);
	void Salto();
	static int GetVida() { return vida; }
	static int GetPuntuacion() { return puntuacion; }
	static void SetPuntuacion(int suma, bool poner_cero);
	static void SetVida(int num) { vida = num; }
	void CambiaEstado();
	void Rebote_escenario(float &posOJO, float xmax, float xmin);
	friend class Interaccion;
};

