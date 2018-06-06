#include "Llave.h"
#include "glut.h"
#include "Constantes.h"

Llave::Llave(Vector pos): Transportable(pos, TAMANIO),num(1)
{}
Llave::Llave(): Transportable({2,44}, TAMANIO), num(1) {}

Llave::~Llave()
{
}

void Llave::Dibuja()
{
	glColor3b(252,234, 87);
	glTranslatef(posicion.x, posicion.y, 1.5);
	glutSolidCube(Long_caracteristica*2.0f);
	glTranslatef(-posicion.x, -posicion.y, -1.5);
}
