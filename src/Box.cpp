#include "Etsidi.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "Box.h"
#include "glut.h"
#include "Constantes.h"
using namespace ETSIDI;
using namespace std;
Box::Box(Vector pos) :Transportable(pos, TAMANIO) //2*Tamanio =lado
{
	color.SetColor(51, 25, 0);
	tocando = false;
	trans = false;	
}


Box::~Box()
{
}

void Box::Dibuja()
{
	glColor3b(color.rojo,color.verde,color.azul);
	glTranslatef(posicion.x, posicion.y, 1.5);
	glutSolidCube(Long_caracteristica*2.0f);
	glTranslatef(-posicion.x, -posicion.y, -1.5);

	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Textures/Box2.png").id);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0); glVertex3d(posicion.x - Long_caracteristica, posicion.y - Long_caracteristica, 1.5 + Long_caracteristica + 0.1);
	glTexCoord2d(1, 0); glVertex3d(posicion.x - Long_caracteristica, posicion.y + Long_caracteristica, 1.5 + Long_caracteristica + 0.1);
	glTexCoord2d(1, 1); glVertex3d(posicion.x + Long_caracteristica, posicion.y + Long_caracteristica, 1.5 + Long_caracteristica + 0.1);
	glTexCoord2d(0, 1); glVertex3d(posicion.x + Long_caracteristica, posicion.y - Long_caracteristica, 1.5 + Long_caracteristica + 0.1);

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
}
void Box::CambiaEstado() {
	if (trans == true) trans = false;
	else trans = true;
}


