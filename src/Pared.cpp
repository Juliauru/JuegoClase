#include <stdlib.h>
#include "glut.h"
#include "Pared.h"
#include "Constantes.h"
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
	glVertex3d(posicion.x, posicion.y, PROFUNDIDAD_PLATAFORMAS);
	glVertex3d(limite.x, limite.y, PROFUNDIDAD_PLATAFORMAS);
	glVertex3d(limite.x, limite.y, 0);
	glVertex3d(posicion.x, posicion.y, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glEnd();

}
Vector2D& Pared::getLimites()
{
	return limite;
}
float Pared::Distancia(Vector2D punto, Vector2D *direccion) {
	Vector2D u = (punto - posicion);
	Vector2D v = (limite - posicion).unitario();
	float longitud = (posicion - limite).modulo();
	Vector2D dir;
	float valor = u * v;
	float distancia = 0;
	if (valor<0)
		dir = u;
	else if (valor>longitud)
		dir = (punto - limite);
	else
		dir = u - v * valor;
	distancia = dir.modulo();
	if (direccion != 0) //si nos dan un vector…
		*direccion = dir.unitario();
	return distancia;
}
void Pared::setLimites(float v1x, float v1y, float v2x, float v2y) {
	posicion.x = v1x;
	posicion.y = v1y;
	limite.x = v2x;
	limite.y = v2y;
}