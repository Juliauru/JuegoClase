#include "Mundo.h"
#include "glut.h"
#include "Interaccion.h"
#include <math.h>

void Mundo::RotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);	
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}
void Mundo::Dibuja()
{
	escenario.Reorientar();
	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo
	glDisable(GL_LIGHTING);
	escenario.Dibuja();
	personaje.Dibuja();
	glEnable(GL_LIGHTING);
}

void Mundo::Mueve() {
	bool x=false;
	
	for (int i = 0; i < 7; i++) {
		x= Interaccion::Contacto(personaje, escenario.plat[i]);
	}
	personaje.Mueve(0.025f, x);
}

void Mundo::Inicializa()
{
	x_ojo=0;
	y_ojo=10;
	z_ojo=20;
}

void Mundo::Tecla(unsigned char key)
{
	switch (key) {
	case 32:
		personaje.Salto();
	}
}
void Mundo::TeclaEspecial(bool izq,bool der)
{	
	if (izq == true) personaje.getVelocidad().x=-2.5;
	if (der == true) personaje.getVelocidad().x = 2.5;				
}
