#include "ETSIDI.h"
#include "EnemigoD.h"
#include <iostream>
#include <time.h>
using namespace std;
using namespace ETSIDI;

EnemigoD::EnemigoD(Vector pos) :Enemigo(pos), en2("Textures/Enemigo_burned2.png", 2)
{
	getColor().SetColor(145, 145, 37);
	en2.setCenter(posicion.x, posicion.y);
	en2.setPos(posicion.x - 0.5, posicion.y - 0.4);
	en2.setSize(1, 1);
	en2.setState(0);
}


EnemigoD::~EnemigoD(){}
int EnemigoD::EnemEliminado() { //Función polimórfica que hace que este tipo de enemigos sea especial, y da ventajas cuando lo matas
	int i = lanzaDado(4, 1);
	if (i == 1 && Personaje::GetVida() < 3) {
		Personaje::SetVida(Personaje::GetVida() + 1);
	}
	else if (i == 1 && Personaje::GetVida() >= 3) {
		i = 4;
	}
	if (i == 2) {
		Personaje::SetPuntuacion(500, 0);
	}
	return i;// 1-vida, 2-puntos, 3-nada, 4-Todas las vidas cargadas
}
void EnemigoD::Dibuja(){
	glPushMatrix();
	glTranslated(posicion.x, posicion.y, 1.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	en2.draw();
	en2.loop();
	glPopMatrix();
	if (velocidad.x <= 0) {
		en2.setState(0);
	}
	else
		en2.setState(1);
}


