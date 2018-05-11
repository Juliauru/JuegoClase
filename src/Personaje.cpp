#include "Personaje.h"
#include "glut.h"
#include <math.h>


Personaje::Personaje(float a)
{
	vida = 3;
	if (a < 0.5) {
		Long_caracteristica = 0.5;
	}
	else {
		Long_caracteristica = a;
	}
	posicion.x = posicion.y = 0.75f;
	aceleracion.x = 0;
	aceleracion.y = -10.0f;
	velocidad.x = 0;
	velocidad.y = 0;
	
}
Personaje::~Personaje()
{
}
void Personaje::Dibuja()
{
	glColor3b(120, 40, 30);
	glTranslatef(posicion.x, posicion.y, 1.5);
	glutSolidSphere((Long_caracteristica), 20, 30);
	glTranslatef(-posicion.x, -posicion.y, -1.5);
}
//void Personaje::Mueve(float t, bool p) {
//	
//	if(vinicial*vinicial + 2 * aceleracion.y*(posicion.y - posinicial)>0){
//		velocidad.y = sqrt(vinicial*vinicial + 2 * aceleracion.y*(posicion.y - posinicial));
//		posicion = posicion + velocidad*t;
//		}
//	else {
//		vinicial = 0;
//		posinicial = 0;
//		posicion = posicion + velocidad * t + aceleracion * (0.5f*t*t);
//		velocidad = velocidad + aceleracion * t;
//	}
	
	

void Personaje::Salto() { //Poner límtes al salto
	if (fabsf(velocidad.y) < 0.5 && velocidad.y >= 0) {
		vinicial = velocidad.y = 12.0f;
		posinicial = posicion.y;
	}
}
