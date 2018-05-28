#include "Personaje.h"
#include "glut.h"
#include "Constantes.h"
#include <math.h>


Personaje::Personaje() : Movil({ 0.75f,0.75f }, { 0.0f,0.0f }, { 0.0f,-10.0f }, TAMANIO)
{
	vida = 3;
	transportando == false;

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
void Personaje::DibujaVidas(float y,float inc)
{
	float l = 0, plus=inc-7.5;
	for (int i = 0; i < vida; i++) {
		glColor3f(255, 0, 0);
		glTranslatef(((TAMANIO/3)+l),(((int)y/3)+plus), 0);
		glutSolidSphere((TAMANIO / 3), 20, 30);
		glTranslatef(-((TAMANIO / 3)+l), -(((int)y / 3) + plus), 0);
		l = l + TAMANIO;
	}
}

void Personaje::Salto() { //Poner límtes al salto
	if (fabsf(velocidad.y) < 0.1 && velocidad.y >= 0) {
		vinicial = velocidad.y = POTENCIA_SALTO;
		posinicial = posicion.y;
	}
}
float Personaje::Distancia(Vector2D centro, Vector2D *direccion) {
	//Posicion u = (punto - limite1);
	Vector2D dir = (posicion - centro).unitario();
	float distancia = (posicion - centro).modulo();
	*direccion = dir;
	return distancia;
}
void Personaje::CambiaEstado() {
	if (transportando == true) transportando = false;
	else transportando = true;
}
