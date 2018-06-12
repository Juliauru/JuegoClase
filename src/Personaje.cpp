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
Personaje::Personaje() : Movil({ 0.75f,0.75f }, { 0.0f,0.0f }, { 0.0f,-10.0f }, TAMANIO),pers("Textures/Kirby8_burned.png",4)
{
	for (int i = 0; i < 3; i++) {
		sVida[i] = new Sprite("Textures/vida.png");
	}
	pers.setCenter(posicion.x, posicion.y);
	pers.setPos(posicion.x - 0.7, posicion.y - 0.75);
	pers.setSize(1.5, 1.5);
	pers.setState(0);
	transportando = false;
}
Personaje::~Personaje()
{
}
void Personaje::Dibuja()
{
	glPushMatrix();
	glTranslated(posicion.x, posicion.y, 2);
	glColor3f(1.0f, 1.0f, 1.0f);
	pers.draw();
	pers.loop();
	glPopMatrix();
	if (velocidad.x == 0)
		pers.setState(3);
	if (velocidad.x > 0)
		pers.setState(1);
	if (velocidad.x < 0)
		pers.setState(0);
	if (velocidad.y != 0) {
		pers.setState(2);
	}
	/*glColor3b(120, 40, 30);
	glTranslatef(posicion.x, posicion.y, 1.5);
	glutSolidSphere((Long_caracteristica), 20, 30);
	glTranslatef(-posicion.x, -posicion.y, -1.5);*/
}
void Personaje::DibujaVidas(float y,float inc)
{
	//sVida= new Sprite("Textures/vida.png");
	float l = 1.5, plus = inc-ALTURA+0.5;
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
void Personaje::Rebote_escenario(float &posOJO, float xmax, float xmin) {
	Movil::Rebote_escenario(posOJO, xmax, xmin);
	if (posicion.y > (ALTURA + posOJO))
		if ( 50 >= (ALTURA * 2 + posOJO))
			posOJO = posOJO + ALTURA;
		else
			posOJO = 50 - ALTURA;
	if (posicion.y <(posOJO - ALTURA))
		if (0 >= (posOJO - ALTURA * 2))
			posOJO = posOJO - ALTURA;
		else
			posOJO = ALTURA;
}

