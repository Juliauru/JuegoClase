#include "Escenario.h"
#include <stdlib.h>
#include "glut.h"
#include "ETSIDI.h"
using  ETSIDI::getTexture;
Escenario::~Escenario()
{
}
Escenario::Escenario()
{
	p_inicio.getPosicion().setValor(0, 0);
	p_inicio.setLargo(20);	
	plat = new Plataforma[Plataforma::get_nplataformas()]; //Primero siempre posicion antes que longitud de las parede

	plat[0].getPosicion().setValor(5, 1);
	plat[1].getPosicion().setValor(3, 6);
	plat[2].getPosicion().setValor(0, 4);
	plat[3].getPosicion().setValor(10, 6);
	plat[4].getPosicion().setValor(10, 16);
	plat[5].getPosicion().setValor(6, 15);
	plat[6].getPosicion().setValor(10, 7);
	for (int i = 0; i < Plataforma::get_nplataformas(); i++) {
		plat[i].setLargo(rand() % 10 + 1);
		plat[i].getColor().SetColor(153, 255, 51);
	}

	//Limites caja
	limites[0].setLimites(0, 0, 0, 50);
	limites[1].setLimites(0, 50, 20, 50);
	limites[2].setLimites(20, 50, 20, 0);
	limites[3].setLimites(0, 0, 20, 0);

	//limites pared trasera
	vertices[0].setValor(0, 0);
	vertices[1].setValor(0, 50);
	vertices[2].setValor(20, 50);
	vertices[3].setValor(20, 0);

}
void Escenario::Dibuja() {
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	//glColor3ub(colorPared.rojo, colorPared.verde, colorPared.azul);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Textures/Sun.png").id);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0); glVertex3d(vertices[0].x, vertices[0].y, 0);
	glTexCoord2d(1, 0); glVertex3d(vertices[1].x, vertices[1].y, 0);
	glTexCoord2d(1, 1); glVertex3d(vertices[2].x, vertices[2].y, 0);
	glTexCoord2d(0, 1); glVertex3d(vertices[3].x, vertices[3].y, 0);
	glEnd();
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LIGHT0);
	p_inicio.Dibuja();
	for (int i = 0; i < Plataforma::get_nplataformas(); i++) {
		plat[i].Dibuja();
	}
	for (int i = 0; i < 4; i++) {
		limites[i].Dibuja();
	}
	}
void Escenario::Reorientar() {
	gluLookAt(10, 7.5, 25,  // posicion del ojo 0-10-20 x_ojo=0 y=5 z=30
		10, 7.5, -100,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)
}