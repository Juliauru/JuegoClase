#include "Plataforma.h"
#include "Constantes.h"
#include "glut.h"
int Plataforma::n_plataformas = 0;
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
void Plataforma::Dibuja() {
	Pared::Dibuja();
	/*glTranslatef(ESPESOR / 2, -ESPESOR / 2-0.001f, ESPESOR / 2);
	
	for (int i = 0; i <((limite.x-posicion.x) / ESPESOR); i++) {
		glTranslatef(posicion.x + (ESPESOR*i), posicion.y, 0);
		for (int j = 0; j < (PROFUNDIDAD_PLATAFORMAS / ESPESOR); j++) {
			glTranslatef(0, 0, (j*ESPESOR));
			glutSolidCube(ESPESOR);
			glTranslatef(0, 0, -(j*ESPESOR));
		}
		glTranslatef(-(posicion.x + (i*ESPESOR)), -posicion.y, 0);
	}
	glTranslatef(-ESPESOR / 2, ESPESOR / 2, -ESPESOR / 2);
*/
}
int Plataforma::get_nplataformas() {
	return n_plataformas;
}
void Plataforma::set_nplataformas(int n) {
	n_plataformas = n;
}
void Plataforma::setLargo(int l) {
	if (l < 2) { //Hacer 
		l = 2;
	}
	limite = posicion + l;
}