#include <stdlib.h>
#include "glut.h"
#include "Pared.h"
#include "ETSIDI.h"
using ETSIDI::getTexture;

Pared::Pared()//Cambiar de sitio
{
	color.SetColor(204, 0, 153);	
}


Pared::~Pared()
{
}
void Pared::Dibuja() {
	glDisable(GL_LIGHTING);
	glColor3ub(color.rojo, color.verde, color.azul);
	glBegin(GL_POLYGON);
	 glVertex3d(vertices[0].x, vertices[0].y, 2);
	 glVertex3d(vertices[1].x, vertices[1].y, 2);
	 glVertex3d(vertices[2].x, vertices[2].y, 0);
	 glVertex3d(vertices[3].x, vertices[3].y, 0);
	glEnd();	
	glDisable(GL_LIGHTING);	
	glEnable(GL_LIGHT0);
}
void Pared::SetVertices(float v1x, float v1y, float v2x, float v2y) {
	vertices[0].setValor(v1x, v1y);
	vertices[1].setValor(v2x, v2y);
	vertices[2].setValor(v2x, v2y);
	vertices[3].setValor(v1x, v1y);
	}