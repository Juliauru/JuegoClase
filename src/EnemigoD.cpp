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
void EnemigoD::EnemEliminado(char *f) {
	delete(f);
	int i = lanzaDado(4, 1); // 1-vida, 2-puntos, 3-nada
	switch (i) {
	case 1:
	{if (Personaje::vida < 3)
		Personaje::vida++;
	//cout << "Tienes una vida más" << endl;
	f = new char[strlen("Tienes una vida más") + 1];
	strcpy(f, "Tienes una vida más"); }
	break;
	case 2:
	{
		Personaje::puntuacion = Personaje::puntuacion + 500;
		//cout << "Has obtenido un bonus" << endl;
		f = new char[strlen("Has obtenido un bonus") + 1];
		strcpy(f, "Has obtenido un bonus"); 
		break;
	}
	case 3:
	{
		//cout << "No has tenido suerte" << endl;
		f = new char[strlen("No has tenido suerte") + 1];
		strcpy(f, "No has tenido suerte");
		break; }
	}
	
}


