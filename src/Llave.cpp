#include "Llave.h"
#include "glut.h"


Llave::Llave()
{
	Long_caracteristica = TAMANIO;
	posicion.x = 10;
	posicion.y = 3;
}


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
