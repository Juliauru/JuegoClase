#include "ETSIDI.h"
#include "EnemigoD.h"
#include <iostream>
using namespace std;
using namespace ETSIDI;

EnemigoD::EnemigoD(Vector pos) :Enemigo(pos)
{
	getColor().SetColor(145, 145, 37);
}


EnemigoD::~EnemigoD()
{
	int i = lanzaDado(4,1); // 1-vida, 2-puntos, 3-nada
	switch(i) {
		case 1:
		{if (Personaje::vida < 3)
			Personaje::vida++;
		cout << "Tienes una vida más" << endl; }
		break;
		case 2:
		{
		Personaje::puntuacion = Personaje::puntuacion + 500;
		cout << "Has obtenido un bonus" << endl;
		break;
		}
		case 3:
		{
		cout << "No has tenido suerte" << endl; 
		break; }
	}
	}


