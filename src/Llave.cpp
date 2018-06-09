#include "Llave.h"
#include "glut.h"
#include "Constantes.h"

Llave::Llave(Vector pos) : Transportable(pos, TAMANIO), num(1), sprite("Textures/llave.png")
{
	sprite.setCenter(posicion.x, posicion.y);
	sprite.setPos(posicion.x-0.5, posicion.y-0.5);
	sprite.setSize(1, 1);
}
Llave::Llave() : Transportable({ 2,44 }, TAMANIO), num(1), sprite("Textures/llave.png") {
	sprite.setCenter(posicion.x, posicion.y);
	sprite.setPos(posicion.x - 0.5, posicion.y - 0.5);
	sprite.setSize(1, 1);
}

Llave::~Llave()
{
}

void Llave::Dibuja()
{
	glPushMatrix();
	glTranslated(posicion.x, posicion.y, 1.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	sprite.draw();
	glPopMatrix();
	/*glColor3b(252,234, 87);
	glTranslatef(posicion.x, posicion.y, 1.5);
	glutSolidCube(Long_caracteristica*2.0f);
	glTranslatef(-posicion.x, -posicion.y, -1.5);*/
}
void Llave::Moviendo(float x,float y,float l) {
	
	}

