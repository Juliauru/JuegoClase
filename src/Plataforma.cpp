#include "ETSIDI.h"
#include "Plataforma.h"
#include "Constantes.h"
#include "glut.h"
using namespace ETSIDI;
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
void Plataforma::Dibuja(const char *nombre) {
	Pared::Dibuja(nombre);
	Pared p1(posicion.x, posicion.y - ESPESOR, limite.x, limite.y - ESPESOR);
	Pared p2(posicion.x, posicion.y, posicion.x, posicion.y - ESPESOR);
	Pared p3(limite.x, limite.y, limite.x, limite.y - ESPESOR);
	p1.Dibuja(nombre);
	p2.Dibuja(nombre);
	p3.Dibuja(nombre); 	
	
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(nombre).id);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0); glVertex3d(posicion.x, posicion.y, PROFUNDIDAD_PLATAFORMAS);
	glTexCoord2d(1, 0); glVertex3d(limite.x, limite.y, PROFUNDIDAD_PLATAFORMAS);
	glTexCoord2d(1, 1); glVertex3d(limite.x, limite.y - ESPESOR, PROFUNDIDAD_PLATAFORMAS);
	glTexCoord2d(0, 1); glVertex3d(posicion.x, posicion.y - ESPESOR, PROFUNDIDAD_PLATAFORMAS);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);

	
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