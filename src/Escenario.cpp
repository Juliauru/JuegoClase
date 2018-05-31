#include "Escenario.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "glut.h"
#include "ETSIDI.h"
#include "Constantes.h"
using namespace std;
using  ETSIDI::getTexture;
Escenario::~Escenario()
{
}
Escenario::Escenario()
{	
	p_ojo_y = 8.0f;
	int n,l,i=0;
	float x, y, long_x, long_y;
	 char caracter[10];
	 char caracter2[10];
		ifstream fichero("Plataformas.txt");
	if (!fichero)
		cout << "No se puede abrir el fichero" << endl;
	else{
		fichero >> n;
		fichero >> long_x;
		fichero >> long_y;
		vertices[0].setValor(0, 0);
		vertices[1].setValor(0, long_y);
		vertices[2].setValor(long_x, long_y);
		vertices[3].setValor(long_x,0);
		limites[0].setLimites(0, 0, 0, long_y);
		limites[1].setLimites(0, long_y, long_x, long_y);
		limites[2].setLimites(20, long_y, long_x, 0);
		limites[3].setLimites(0, 0, long_x, 0);
		Plataforma::set_nplataformas(n);
		//Primero siempre posicion antes que longitud de las paredes
		fichero >> x;
		while (!fichero.eof()&& i<Plataforma::get_nplataformas()) {
			fichero >> y;
			fichero >> l;
			plat[i] = new Plataforma({x,y}, l);
			fichero >> x;
			i++;
		}
	}
	fichero.close();

	

}
void Escenario::Dibuja() {
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Textures/T_fondo.png").id);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(1, 0); glVertex3d(vertices[0].x, vertices[0].y, 0);
	glTexCoord2d(1, 1); glVertex3d(vertices[1].x, vertices[1].y, 0);
	glTexCoord2d(0, 1); glVertex3d(vertices[2].x, vertices[2].y, 0);
	glTexCoord2d(0, 0); glVertex3d(vertices[3].x, vertices[3].y, 0);
	glEnd();
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LIGHT0);
	for (int i = 0; i < Plataforma::get_nplataformas(); i++) {
		plat[i]->Dibuja("Textures/T_plat.png");
	}
	for (int i = 0; i < 4; i++) {
		limites[i].Dibuja("Textures/T_limites.png");
	}
	

	}
void Escenario::Reorientar() {
	gluLookAt(10, p_ojo_y, 25,  // posicion del ojo 0-10-20 x_ojo=0 y=5 z=30
		10, p_ojo_y, -100,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)
}