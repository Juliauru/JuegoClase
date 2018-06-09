#include "ETSIDI.h"
#include "Personaje.h"
#include "glut.h"
#include "Constantes.h"
#include <math.h>
#include <iostream>
using ETSIDI::Sprite;
using namespace std;

int Personaje::vida = 3;
int Personaje::puntuacion = 0;
Personaje::Personaje() : Movil({ 0.75f,0.75f }, { 0.0f,0.0f }, { 0.0f,-10.0f }, TAMANIO)
{
	for (int i = 0; i < 3; i++) {
		sVida[i] = new Sprite("Textures/vida.png");
	}

	transportando = false;
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
	//sVida= new Sprite("Textures/vida.png");
	float l = 1.5, plus = inc-7.5;
	for (int i = 0; i < vida; i++) {
		sVida[i]->setCenter(((TAMANIO / 3) + l), (((int)y / 3) + plus)-1);
		sVida[i]->setPos(((TAMANIO / 3) + l-0.5) , (((int)y / 3) + plus)-1.5);
		sVida[i]->setSize(1, 1);
		glPushMatrix();
		glTranslated(((TAMANIO / 3) + l)-0.5, (((int)y / 3) + plus)-1.5, 3.5);
		glColor3f(1.0f, 1.0f, 1.0f);
		sVida[i]->draw();
		glPopMatrix();
		l = l + TAMANIO*2;
	}	
	char punt[10];
	itoa(puntuacion, punt, 10);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	ETSIDI::printxy("Puntos:", 16, (((int)y / 3) + plus) - 0.5, 3.5);
	ETSIDI::printxy(punt, 19, (((int)y / 3) + plus) - 0.5, 3.5);
}

void Personaje::Salto() { //Poner límtes al salto
	if (fabsf(velocidad.y) < 0.1 && velocidad.y >= 0) {
		vinicial = velocidad.y = POTENCIA_SALTO;
		posinicial = posicion.y;
	}
}
void Personaje::CambiaEstado() {
	if (transportando == true) transportando = false;
	else transportando = true;
}

