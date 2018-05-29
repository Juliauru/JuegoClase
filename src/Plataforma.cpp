#include "Plataforma.h"
#include "Constantes.h"
#include "glut.h"
int Plataforma::n_plataformas = 0;
Plataforma::Plataforma(Vector pos,int l):Pared(pos)
{
	if (l < 2) { //Hacer 
		l = 2;
	}
	limite = posicion + l;
	color.SetColor(153, 255, 51);
}
Plataforma::Plataforma(float v1x, float v1y, float v2x, float v2y):Pared(v1x, v1y,v2x,v2y) {
	color.SetColor(153, 255, 51);
}
Plataforma::Plataforma() : Pared(0, 0, 0, 0) {}
Plataforma::~Plataforma()
{
}
void Plataforma::Dibuja() {
	Pared::Dibuja();
	Pared p1(posicion.x, posicion.y - ESPESOR, limite.x, limite.y - ESPESOR);
	Pared p2(posicion.x, posicion.y, posicion.x, posicion.y - ESPESOR);
	Pared p3(limite.x, limite.y, limite.x, limite.y - ESPESOR);
	p1.Dibuja();
	p2.Dibuja();
	p3.Dibuja(); //No funciona
	
	glDisable(GL_LIGHTING);
	glColor3ub(color.rojo, color.verde, color.azul);
	glBegin(GL_POLYGON);
	glVertex3d(posicion.x, posicion.y, PROFUNDIDAD_PLATAFORMAS);
	glVertex3d(limite.x, limite.y, PROFUNDIDAD_PLATAFORMAS);
	glVertex3d(limite.x, limite.y-ESPESOR, PROFUNDIDAD_PLATAFORMAS);
	glVertex3d(posicion.x, posicion.y-ESPESOR, PROFUNDIDAD_PLATAFORMAS);
	glEnd();
	glEnable(GL_LIGHTING);
	glEnd();

	
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
	glTranslatef(-ESPESOR / 2, ESPESOR / 2, -ESPESOR / 2);*/

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