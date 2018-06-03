#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Mundo.h"
#include "glut.h"
#include "Interaccion.h"
using namespace std;
//void Mundo::RotarOjo()
//{
//	float dist = sqrt(x_ojo*x_ojo + z_ojo * z_ojo);
//	float ang = atan2(z_ojo, x_ojo);
//	ang += 0.05f;
//	x_ojo = dist * cos(ang);
//	z_ojo = dist * sin(ang);
//}

void Mundo::Dibuja()
{
	escenario.Reorientar();
	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo
	glEnable(GL_LIGHTING);
	escenario.Dibuja();
	personaje.Dibuja();
	enemigos.Dibuja();
	llave.Dibuja();
	cajas.Dibuja();	
	//DIBUJO DE LAS VIDAS
	personaje.DibujaVidas(escenario.vertices[1].y,escenario.p_ojo_y);
	glEnable(GL_LIGHTING);
}

void Mundo::Mueve() {

	personaje.Mueve(0.025f);
	enemigos.Mueve(0.025f);	
	cajas.Mueve(0.025f);
	for (int i = 0; i < Plataforma::get_nplataformas(); i++) {
		Interaccion::Contacto(personaje, *(escenario.plat[i]));
		enemigos.Rebote(*(escenario.plat[i]));
		cajas.Caida(*(escenario.plat[i]));
	}
	enemigos.Rebote(personaje,cajas);
	enemigos.Rebote();
	Interaccion::Rebote(personaje, escenario);
	enemigos.Rebote(escenario);
	cajas.Contacto(personaje);
	cajas.Mover(personaje);
	enemigos.Eliminar(enemigos.Colision(personaje));
	enemigos.Choque(cajas);
	enemigos.Eliminar(enemigos.Contacto(cajas),true);
	SetOportunidad(personaje);
}
void Mundo::Inicializa()
{
	oportunidad = personaje.GetVida();
	escenario.setFichero("Plataformas.txt"); //Cambiará para cada nivel 	
	enemigos.CreaEnemigos("EnemigosDesdeElPrincipio.txt");
	cajas.CreaCajas("Cajas.txt");

}

bool Mundo::GetOportunidad()
{
	if (oportunidad <= 0) {
		return true;
	}
	else {
		return false;
	}
}

void Mundo::SetOportunidad(Personaje p)
{
	oportunidad = p.GetVida();
}

void Mundo::Tecla(unsigned char key)
{
	switch (key) {
	case 32:
		personaje.Salto();
	}
}
void Mundo::TeclaEspecial(bool izq, bool der, bool coge)
{
	if (izq == true) personaje.getVelocidad().x = -2.5;
	if (der == true) personaje.getVelocidad().x = 2.5;
	if (coge == true) {
		cajas.Coger(personaje);
	}
}
void Mundo::TeclaEspecial2(unsigned char key) {
	switch (key)
	{
	case GLUT_KEY_LEFT:
		personaje.getVelocidad().x = 0.0f;
		break;
	case GLUT_KEY_RIGHT:
		personaje.getVelocidad().x = 0.0f;
		break;

	}
}