#include "Enemigo.h"
#include "Constantes.h"
#include "glut.h"



Enemigo::Enemigo(Vector pos):Movil(pos, {0.0f,0.0f}, { 0.0f,-3.0f }, TAMANIO/1.5f), en1("Textures/Enemigo_burned.png", 2)
{	
	en1.setCenter(posicion.x, posicion.y);
	en1.setPos(posicion.x - 0.5, posicion.y - 0.4);
	en1.setSize(1, 1);
	en1.setState(0);
	getColor().SetColor(0, 40, 30);
	first_time = true;
}


Enemigo::~Enemigo()
{}
int Enemigo::EnemEliminado() { 
	return 0;
}
void Enemigo::Dibuja()
{
	glPushMatrix();
	glTranslated(posicion.x, posicion.y, 1.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	en1.draw();
	en1.loop();
	glPopMatrix();
	if (velocidad.x <= 0) {
		en1.setState(0);
	}
	else
		en1.setState(1);

}

void Enemigo::Rebote_escenario(float &posOJO, float xmax, float xmin) {
	if (posicion.x >= xmax) velocidad.x = -velocidad.x;
	if (posicion.x <= xmin) velocidad.x = -velocidad.x;
}
float Enemigo::Rebote_plat(float dis, float xmax, float xmin) {
	float dif;
	dif=Movil::Rebote_plat(dis,xmax,xmin);
	if (dif <= 0.0f)
	{
		if (first_time == true) {
			if ((rand() % 2) == 0) {
				velocidad.setValor(2.0f, 0.0f);
			}
			else
				velocidad.setValor(-2.0f, 0.0f);
			first_time = false;
		}
		float no;
		Enemigo::Rebote_escenario(no, xmax, xmin);
		return dif;
	}
}




