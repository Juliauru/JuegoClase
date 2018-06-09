#include "ETSIDI.h"
#include "EnemigoD.h"
#include <iostream>
#include <time.h>
using namespace std;
using namespace ETSIDI;

EnemigoD::EnemigoD(Vector pos) :Enemigo(pos)
{
	getColor().SetColor(145, 145, 37);
}


EnemigoD::~EnemigoD(){}
int EnemigoD::EnemEliminado() {
	char *f;
	int i = lanzaDado(4, 1);
	if (i == 1 && Personaje::vida < 3) {
		Personaje::vida++;
	}
	if (i == 1 && Personaje::vida >= 3) {
		i = 4;
	}
	if (i == 2) {
		Personaje::puntuacion = Personaje::puntuacion + 500;
	}
	return i;// 1-vida, 2-puntos, 3-nada
}


