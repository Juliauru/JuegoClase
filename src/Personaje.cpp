#include "Personaje.h"
#include "glut.h"
#include <math.h>

Personaje::Personaje(float a)
{
	if (a < 0.1) {
		altura = 1;
	}
	else {
		altura = a;
	}
	posicion.x = posicion.y = aux= 0.75f;
	aceleracion.x = 0;
	aceleracion.y = -10.0f;
	velocidad.x = 0;
	velocidad.y = 0;
	vinicial = 0;
	Long_caracteristica = altura; //Se debe hacer de otra forma 
	
}
Personaje::~Personaje()
{
}
void Personaje::Dibuja()
{
	glColor3b(120, 40, 30);
	glTranslatef(posicion.x, posicion.y, 1.5);
	glutSolidSphere((altura / 2), 20, 30);
	glTranslatef(-posicion.x, -posicion.y, -1.5);
}
void Personaje::Mueve(float t) {

	if(vinicial*vinicial + 2 * aceleracion.y*(posicion.y - posinicial)>0){
		velocidad.y = sqrt(vinicial*vinicial + 2 * aceleracion.y*(posicion.y - posinicial));
		posicion = posicion + velocidad*t;
		aux = posicion.y+0.001;
	}
	else {
		vinicial = 0;
		posinicial = 0;
		//velocidad.y = -sqrt(2 * aceleracion.y*(posicion.y-aux));
		posicion = posicion + velocidad * t + aceleracion * (0.5f*t*t);
		velocidad = velocidad + aceleracion * t;
	}
	
	
}
void Personaje::Salto() { //Poner límtes al salto

		vinicial = velocidad.y = 8.0f;
		posinicial = posicion.y;
		}