#include <stdlib.h>
#include "glut.h"
#include "Pared.h"
#include "Constantes.h"
#include "ETSIDI.h"
using ETSIDI::getTexture;

Pared::Pared(Vector pos): Objeto(pos)
{
	color.SetColor(204, 0, 153);
}
Pared::Pared(float v1x, float v1y, float v2x, float v2y) : Objeto({ v1x,v1y })
{
	limite.setValor(v2x, v2y);
	color.SetColor(204, 0, 153);
}
Pared::Pared() : Objeto({ 0.0f,0.0f }) {}

Pared::~Pared()
{
}
void Pared::Dibuja(const char *nombre) {
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	//glColor3ub(colorPared.rojo, colorPared.verde, colorPared.azul);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(nombre).id);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0); glVertex3d(posicion.x, posicion.y, PROFUNDIDAD_PLATAFORMAS);
	glTexCoord2d(1, 0); glVertex3d(limite.x, limite.y, PROFUNDIDAD_PLATAFORMAS);
	glTexCoord2d(1, 1); glVertex3d(limite.x, limite.y, 0);
	glTexCoord2d(0, 1); glVertex3d(posicion.x, posicion.y, 0);	
	glEnd();
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LIGHT0);
	}
Vector& Pared::getLimites()
{
	return limite;
}
float Pared::Distancia(Vector punto, Vector *direccion) {
	Vector u = (punto - posicion);
	Vector v = (limite - posicion).unitario();
	float longitud = (posicion - limite).modulo();
	Vector dir;
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