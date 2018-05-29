#include "Llave.h"
#include "glut.h"
#include "Constantes.h"

Llave::Llave(Vector pos): Transportable(pos, TAMANIO)
{}
Llave::Llave(): Transportable({10,3}, TAMANIO){}

Llave::~Llave()
{
}

void Llave::Dibuja()
{
	glColor3b(252,234, 87);
	glTranslatef(posicion.x, posicion.y, 1.5);
	glutSolidCube(Long_caracteristica);
	glTranslatef(-posicion.x, -posicion.y, -1.5);
}
