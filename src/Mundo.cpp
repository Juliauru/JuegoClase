#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Mundo.h"
#include "glut.h"
#include "Interaccion.h"
#include <time.h>
using namespace std;

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
	DibujaFrase(texto, escenario.vertices[1].y, escenario.p_ojo_y);
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
	enemigos.Rebote(personaje,cajas,llave);
	enemigos.Rebote();
	Interaccion::Rebote(personaje, escenario);
	enemigos.Rebote(escenario);
	cajas.Contacto(personaje);
	cajas.Mover(personaje,llave);
	cajas.Rebote(escenario);
	texto=enemigos.Eliminar(enemigos.Colision(personaje));
	enemigos.Choque(cajas);
	enemigos.Eliminar(enemigos.Contacto(cajas),true);
	SetOportunidad(personaje);
	Interaccion::Contacto(personaje, llave);
	Interaccion::Mover(personaje, llave);
	enemigos.Choque(llave);
	Interaccion::EncuentroFinal(llave, escenario);

}
void Mundo::Inicializa()
{
	//llave.num = 1;
	nivel = 0;
	texto = 0;
	fich = new char[2];
	strcpy(fich, " ");
	time(&tiempo);
	//personaje.SetVida(3);
	oportunidad = personaje.GetVida();
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
		break;
	case 'v':
		personaje.SetPos(4, 44);
		break;
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
	personaje.SetPos(0.75,0.75);
	personaje.SetVida(3);
	texto = 0;
	oportunidad = personaje.GetVida();
	llave.InicioValor();

	if (nivel == 1)
	{
		//EL DE VERDAD
		llave.SetPos(1, 26+(llave.get_LCaract()));
		//MA�ANA PARA RAQUEL
		//llave.SetPos(2, 40+ (llave.get_LCaract()));
		escenario.setFichero("Plataformas.txt"); //Cambiar� para cada nivel 	
		enemigos.CreaEnemigos("Enemigos1.txt");
		cajas.CreaCajas("Cajas.txt");
	}
	if (nivel == 2)
	{
		escenario.setFichero("Plataformas2.txt"); //Cambiar� para cada nivel 	
		enemigos.CreaEnemigos("EnemigosDesdeElPrincipio2.txt");
		cajas.CreaCajas("Cajas2.txt");
	}
	if (nivel == 3)
	{
		escenario.setFichero("Plataformas3.txt"); //Cambiar� para cada nivel 	
		enemigos.CreaEnemigos("EnemigosDesdeElPrincipio3.txt");
		cajas.CreaCajas("Cajas3.txt");
	}
	if (nivel <= 3)
		return true;
	return false;
}
void Mundo::DibujaFrase(int i, float y, float inc) {

	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	switch (i) {
	case 1:	{
		fich = new char[strlen("Has obtenido un vida extra") + 1];
		strcpy(fich, "HAS OBTENIDO UNA VIDA EXTRA");
		time(&tiempo);
		break;
	}
	case 4: {
		fich = new char[strlen("Nivel de vida maximo") + 1];
		strcpy(fich, "TIENES LAS VIDAS AL MAXIMO");
		time(&tiempo); }
		break;
	case 2: {
		fich = new char[strlen("Has obtenido un bonus") + 1];
		strcpy(fich, "HAS OBTENIDO UN BONUS  +500 ");
		time(&tiempo);
		break;
	}
	case 3: {
		fich = new char[strlen("No has tenido suerte") + 1];
		strcpy(fich, "NO HAS TENIDO SUERTE");
		time(&tiempo);
		break; }
	}
	if (time(NULL) <= tiempo + 2)
		ETSIDI::printxy(fich, 5, escenario.p_ojo_y + 1,3.5);
}

float Mundo::GetEscenarioAltura()
{
	return escenario.p_ojo_y;
}
