#include <math.h>
#include "Mundo.h"
#include "glut.h"
#include "Interaccion.h"

void Mundo::RotarOjo()
{
	float dist = sqrt(x_ojo*x_ojo + z_ojo * z_ojo);
	float ang = atan2(z_ojo, x_ojo);
	ang += 0.05f;
	x_ojo = dist * cos(ang);
	z_ojo = dist * sin(ang);
}
void Mundo::Dibuja()
{
	escenario.Reorientar();
	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo
	glDisable(GL_LIGHTING);
	escenario.Dibuja();
	personaje.Dibuja();
	enemigos.Dibuja();
	llave.Dibuja();
	cajas.Dibuja();
	glEnable(GL_LIGHTING);
}

void Mundo::Mueve() {

	personaje.Mueve(0.025f);
	enemigos.Mueve(0.025f);
	for (int i = 0; i < Plataforma::get_nplataformas(); i++) {
		Interaccion::Contacto(personaje, escenario.plat[i]);
		enemigos.Rebote(escenario.plat[i]);
	}
	Interaccion::Contacto(personaje, escenario.p_inicio);
	enemigos.Rebote(escenario.p_inicio);
	enemigos.Rebote(personaje);
	enemigos.Rebote();
	Interaccion::Rebote(personaje, escenario);
	enemigos.Rebote(escenario);
}
void Mundo::Inicializa()
{
	x_ojo = 0;
	y_ojo = 10;
	z_ojo = 20;
	for (int i = 0; i < 5; i++) {
		Enemigo *aux = new Enemigo;
		aux->SetPos(i, 1 + 3 * i);
		//aux->setAltura(0.25);
		enemigos.Agregar(aux);
	}
	for (int i = 0; i < 8; i++) {
		Enemigo *aux = new Enemigo;
		aux->SetPos(i + 2, 1 + 3 * i);
		//aux->setAltura(0.25);
		enemigos.Agregar(aux);
	}
	cajas.CreaCajas();
}

void Mundo::Tecla(unsigned char key)
{
	switch (key) {
	case 32:
		personaje.Salto();
	}
}
void Mundo::TeclaEspecial(bool izq, bool der)
{
	if (izq == true) personaje.getVelocidad().x = -2.5;
	if (der == true) personaje.getVelocidad().x = 2.5;
}