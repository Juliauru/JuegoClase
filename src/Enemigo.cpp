#include "Enemigo.h"
#include "glut.h"



Enemigo::Enemigo()
{
	Long_caracteristica = 0.8;
	posicion.x = 0;
	velocidad.x = 0.0f;
	velocidad.y = 0.0;
	posicion.y = 1;
	aceleracion.x = 0;
	aceleracion.y = -10.0f;
}


Enemigo::~Enemigo()
{
}

void Enemigo::Dibuja()
{
	glColor3b(0, 40, 30);
	glTranslatef(posicion.x, posicion.y, 1.5);
	glutSolidSphere((Long_caracteristica / 2), 20, 30);
	glTranslatef(-posicion.x, -posicion.y, -1.5);
}

void Enemigo::setAltura(float a)
{
	if (a<0.01) {
		Long_caracteristica = 0.8;
	}
	else {
		Long_caracteristica = a;
	}
}
void Enemigo::Caida(float t) {
	velocidad.y = velocidad.y - (0.5*aceleracion.y*t*t);
	posicion.y = posicion.y + velocidad.y*t;
}
/*void Enemigo::Mueve(float t)
{
velocidad =velocidad +(0.5*aceleracion.y*t*t);
posicion= posicion + velocidad*t;
/*for (int i = 0; i < Plataforma::get_nplataformas(); i++){
if (Interaccion::Contacto(*this, Escenario::*(plat[i])) {
//Prueba por el momento para que no se vaya al infinito
if (posicion.x>20) {
velocidad.x = -velocidad.x;
}
else if (posicion.x < 0) {
velocidad.x = -velocidad.x;
}
//Interación con los límites de la caja del juego hará que la velocidad varíe de signo y se de la vuelta
}*/

