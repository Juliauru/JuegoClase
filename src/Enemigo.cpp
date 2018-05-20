#include "Enemigo.h"
#include "Constantes.h"
#include "glut.h"



Enemigo::Enemigo()
{
	Long_caracteristica = TAMANIO / 1.5f;
	posicion.x = 0;
	velocidad.x = 0.0f;
	velocidad.y = 0.0;
	posicion.y = 1;
	aceleracion.x = 0;
	aceleracion.y = -3.0f;
}


Enemigo::~Enemigo()
{
}

void Enemigo::Dibuja()
{
	glColor3b(0, 40, 30);
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
float Enemigo::Distancia(Vector2D centro, Vector2D *direccion) {
	Vector2D dir = (posicion - centro).unitario();
	float distancia = (posicion - centro).modulo();
	*direccion = dir;
	return distancia;
}

