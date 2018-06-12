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

void Mundo::Destruye()  //Elimina los objetos reservados en memoria
{
	escenario.DestruirContenido();
	cajas.DestruirContenido();
	enemigos.DestruirContenido();
	Personaje::SetPuntuacion(0, 1);
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
	texto=enemigos.Eliminar(enemigos.Colision(personaje)); //La función enemigos devuelve un int que corresponde al mensaje que hay que mostrar por pantalla.
	enemigos.Choque(cajas);
	enemigos.Eliminar(enemigos.Contacto(cajas),true);
	SetOportunidad(personaje);
	Interaccion::Mover(personaje, llave);
	Interaccion::EncuentroFinal(llave, escenario);

}
void Mundo::Inicializa()
{
	nivel = 0;
	texto = 0;
	fich = new char[2];
	strcpy(fich, " ");
	time(&tiempo);
	oportunidad = personaje.GetVida();
	CargarNivel();

}

bool Mundo::GetOportunidad() //Si no hay oportunidades el juego se termina
{
	if (oportunidad <= 0) {
		return true;
	}
	else {
		return false;
	}
}

void Mundo::SetOportunidad(Personaje p) //Asocia las oportunidades de poder pasarse el juego con las vidas del personaje
{
	oportunidad = p.GetVida();
}

bool Mundo::GetLlave() //Informa de cuando no hay llave en el nivel, lo cuál significaría que se ha superado el nivel con éxito
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
	case 'v': //Atajo para facilitar la corrección del profesor, pero que después será eliminado
		switch (nivel) {
		case 1:
			personaje.SetPos(4, 44);
			break;
		case 2:
			personaje.SetPos(5, 43);
			break;
		case 3:
			personaje.SetPos(15, 46);
			break;
		}
		
		break;
	}
}
void Mundo::TeclaEspecial(bool izq, bool der, bool coge) //Se utilizan flags para que sea más rapida la ejecución del cóigo
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
	if (nivel > 0) { //Cuando ya haya un nivel dibujado y se termine, al cargar el siguiente nivel entrará aquí para borrar los objetos reservados en memoria
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

		llave.SetPos(1, 26+(llave.get_LCaract()));
		escenario.setFichero("Plataformas.txt");	
		enemigos.CreaEnemigos("Enemigos1.txt");
		cajas.CreaCajas("Cajas.txt");

	}
	if (nivel == 2)
	{
		llave.SetPos(17, 18 + (llave.get_LCaract()));
		escenario.setFichero("Plataformas2.txt"); 	
		enemigos.CreaEnemigos("Enemigos2.txt");
		cajas.CreaCajas("Cajas2.txt");
	}
	if (nivel == 3)
	{
		llave.SetPos(18, 45 + (llave.get_LCaract()));
		escenario.setFichero("Plataformas3.txt"); 	
		enemigos.CreaEnemigos("Enemigos3.txt");
		cajas.CreaCajas("Cajas3.txt");
	}
	if (nivel <= 3)
		return true;
	return false;
}
void Mundo::DibujaFrase(int i, float y, float inc) { //Escribe encima del juego un pequeño mensaje, sobre lo que ha ocurrido al matar a un enemigo especial

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

float Mundo::GetEscenarioAltura() //Devuelve la posición del ojo en y del escenario
{
	return escenario.p_ojo_y;
}
