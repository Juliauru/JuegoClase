#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "Box.h"
#include "glut.h"
using namespace std;
Box::Box()
{
	tocando = false;
	trans = false;
	Long_caracteristica = TAMANIO*2.0f;
	posicion.x = posicion.y = 0 + Long_caracteristica / 2;
}
Box::~Box()
{
}

void Box::Dibuja()
{
	glColor3b(color.rojo,color.verde,color.azul);
	glTranslatef(posicion.x, posicion.y, 1.5);
	glutSolidCube(Long_caracteristica);
	glTranslatef(-posicion.x, -posicion.y, -1.5);
}
void Box::CambiaEstado() {
	if (trans == true) trans = false;
	else trans = true;	
}


