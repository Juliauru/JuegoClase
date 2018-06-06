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

void Mundo::Destruye()
{
	escenario.DestruirContenido();
	cajas.DestruirContenido();
	enemigos.DestruirContenido();
}

void Mundo::Mueve() {

	personaje.Mueve(0.025f);
	enemigos.Mueve(0.025f);	
	cajas.Mueve(0.025f);
	llave.Mueve(0.025f);
	for (int i = 0; i < Plataforma::get_nplataformas(); i++) {
		Interaccion::Contacto(personaje, *(escenario.plat[i]));
		enemigos.Rebote(*(escenario.plat[i]));
		cajas.Caida(*(escenario.plat[i]));
		Interaccion::Contacto(llave, *(escenario.plat[i]));
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
	Interaccion::Contacto(personaje, llave);
	Interaccion::Mover(personaje, llave);
	enemigos.Choque(llave);
	//CONDICION DE PRUEBA
	if (llave.getPosicion().x>5 && llave.getPosicion().y > 6) {
		llave.num = 0;
	}
}
void Mundo::Inicializa()
{
	//llave.num = 1;
	nivel = 0;
	//personaje.SetVida(3);
	oportunidad = personaje.GetVida();
	//escenario.setFichero("Plataformas.txt"); //Cambiará para cada nivel 	
	//enemigos.CreaEnemigos("EnemigosDesdeElPrincipio.txt");
	//cajas.CreaCajas("Cajas.txt");
	CargarNivel();

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

bool Mundo::GetLlave()
{
	if (llave.ValorLlave() == 0) {
		return true;
	}
	else {
		return false;
	}
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
		Interaccion::Coger(personaje, llave);
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
bool Mundo::CargarNivel()
{
	if (nivel > 0) {
		escenario.DestruirContenido();
		cajas.DestruirContenido();
		enemigos.DestruirContenido();
	}
	nivel++;
	personaje.SetPosicion(0.75,0.75);
	personaje.SetVida(3);
	oportunidad = personaje.GetVida();
	llave.num = 1;

	if (nivel == 1)
	{
		escenario.setFichero("Plataformas.txt"); //Cambiará para cada nivel 	
		enemigos.CreaEnemigos("EnemigosDesdeElPrincipio.txt");
		cajas.CreaCajas("Cajas.txt");
	}
	if (nivel == 2)
	{
		escenario.setFichero("Plataformas2.txt"); //Cambiará para cada nivel 	
		enemigos.CreaEnemigos("EnemigosDesdeElPrincipio2.txt");
		cajas.CreaCajas("Cajas2.txt");
	}
	if (nivel == 3)
	{
		//escenario.setFichero("Plataformas.txt"); //Cambiará para cada nivel 	
		//enemigos.CreaEnemigos("EnemigosDesdeElPrincipio.txt");
		//cajas.CreaCajas("Cajas.txt");
	}
	if (nivel <= 3)
		return true;
	return false;
}