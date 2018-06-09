#include "Enemigo.h"
#include "Constantes.h"
#include "glut.h"



Enemigo::Enemigo(Vector pos):Movil(pos, {0.0f,0.0f}, { 0.0f,-3.0f }, TAMANIO/1.5f) //La aceleración??
{
	getColor().SetColor(0, 40, 30);
}


Enemigo::~Enemigo()
{}
void Enemigo::EnemEliminado( char* f) { 
	delete f;
f = new char[1];
strcpy(f, " ");
}
void Enemigo::Dibuja()
{
	glColor3b(getColor().rojo, getColor().verde, getColor().azul);
	glTranslatef(posicion.x, posicion.y, 1.5);
	glutSolidSphere((Long_caracteristica), 20, 30);
	glTranslatef(-posicion.x, -posicion.y, -1.5);
}

void Enemigo::setAltura(float a) //ESTA FUNCION LA ELIMINARIA PARA NO PODER VARIAR EL TAMAÑO O NO LA USARIA EN MUNDO
{
	if (a<0.01) {
		Long_caracteristica = 0.25;
	}
	else {
		Long_caracteristica = a;
	}
}




