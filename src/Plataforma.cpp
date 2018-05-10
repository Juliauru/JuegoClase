#include "Plataforma.h"
#include "glut.h"
int Plataforma::n_plataformas = 7;
Plataforma::Plataforma(int l)
{
	if (l < 2) { //Hacer 
		l = 2;
	}
	limite = posicion + l;
}

Plataforma::~Plataforma()
{
}
//void Plataforma::Dibuja() {
//	glColor3ub(color.rojo, color.verde, color.azul);
//	glTranslatef(lado / 2, lado / 2, lado / 2);
//	for (int i = 0; i <(largo / lado); i++) {
//		glTranslatef(posicion.x + (lado*i), posicion.y, 0);
//		for (int j = 0; j < (ancho / lado); j++) {
//			glTranslatef(0, 0, (j*lado));
//			glutSolidCube(lado);
//			glTranslatef(0, 0, -(j*lado));
//		}
//		glTranslatef(-(posicion.x + (i*lado)), -posicion.y, 0);
//	}
//	glTranslatef(-lado / 2, -lado / 2, -lado / 2);
//
//}
int Plataforma::get_nplataformas() {
	return n_plataformas;
}
void Plataforma::setLargo(int l) {
	if (l < 2) { //Hacer 
		l = 2;
	}
	limite = posicion + l;
}