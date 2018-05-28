#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "Box.h"
#include "glut.h"
#include "Constantes.h"
using namespace std;
Box::Box(Vector2D pos) :Transportable(pos, TAMANIO)
{
	color.SetColor(145, 28, 226);
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
}
void Box::CambiaEstado() {
	if (trans == true) trans = false;
	else trans = true;
}


