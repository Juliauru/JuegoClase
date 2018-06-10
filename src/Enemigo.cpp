#include "Enemigo.h"
#include "Constantes.h"
#include "glut.h"



Enemigo::Enemigo(Vector pos):Movil(pos, {0.0f,0.0f}, { 0.0f,-3.0f }, TAMANIO/1.5f), en1("Textures/Enemigo_burned.png", 2)
{	
	en1.setCenter(posicion.x, posicion.y);
	en1.setPos(posicion.x - 0.5, posicion.y - 0.5);
	en1.setSize(1.25, 1.25);
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

	/*glColor3b(getColor().rojo, getColor().verde, getColor().azul);
	glTranslatef(posicion.x, posicion.y, 1.5);
	glutSolidSphere((Long_caracteristica), 20, 30);
	glTranslatef(-posicion.x, -posicion.y, -1.5);*/
}

//void Enemigo::setAltura(float a) //ESTA FUNCION LA ELIMINARIA PARA NO PODER VARIAR EL TAMAÑO O NO LA USARIA EN MUNDO
//{
//	if (a<0.01) {
//		Long_caracteristica = 0.25;
//	}
//	else {
//		Long_caracteristica = a;
//	}
//}




