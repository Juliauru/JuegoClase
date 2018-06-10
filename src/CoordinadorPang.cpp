#include "CoordinadorPang.h"
#include "ETSIDI.h"

CoordinadorPang::CoordinadorPang()
{
	estado = INICIO;
}


CoordinadorPang::~CoordinadorPang()
{
}

void CoordinadorPang::TeclaEspecial(bool izq, bool der, bool coge)
{
	if (estado == JUEGO)
		mundo.TeclaEspecial(izq,der,coge);
}
void CoordinadorPang::TeclaEspecial2(unsigned char key)
{
	if (estado == JUEGO)
		mundo.TeclaEspecial2(key);
}

void CoordinadorPang::Tecla(unsigned char key)
{
	if (estado == INICIO)
	{
		if (key == 'e'|| key == 'E')
		{
			mundo.Inicializa();
			estado = JUEGO;
		}
		if (key == 's'|| key == 'S')
			exit(0);
	}
	else if (estado == JUEGO)
	{
		mundo.Tecla(key);
		if (key == 'p'|| key == 'P') {
			estado = PAUSE;
		}

	}
	else if (estado == GAMEOVER)
	{
		if (key == 'c'|| key == 'C') {
			estado = INICIO;
			mundo.Destruye();
		}
		if (key == 's'|| key == 'S')
			exit(0);
		
	}
	else if (estado == FIN)
	{
		if (key == 'c'|| key == 'C')
	
			estado = INICIO;
			
			
			
	}
	else if(estado == PAUSE) {
		if (key == 'p' || key == 'P') {
			estado = JUEGO;
		}
			if (key == 's' || key == 'S'){
				estado=INICIO;
		}
	}
	else if (estado == TRANSICION) {
		if (key == 'n'|| key == 'N') {
			estado = JUEGO;
		}
	}
}

void CoordinadorPang::Mueve()
{
	if (estado == JUEGO)
	{
		mundo.Mueve();
		if (mundo.GetLlave())
		{
			if (!mundo.CargarNivel()) {
				estado = FIN;
			}
			else {
				estado = TRANSICION;	
			}
		}
		if (mundo.GetOportunidad())
		{
			estado = GAMEOVER;
		}
	}
}


void CoordinadorPang::Dibuja()
{

	if (estado == INICIO) {
		//CODIGO PARA PINTAR UNA PANTALLA NEGRA CON LETRAS
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		glEnable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Textures/Inicio.png").id);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(1, 0); glVertex3d(14, 18, 1);
		glTexCoord2d(1, 1); glVertex3d(14, -4, 1);
		glTexCoord2d(0, 1); glVertex3d(-15, -4, 1);
		glTexCoord2d(0, 0); glVertex3d(-15, 18, 1);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);

	}
	else if (estado == JUEGO)
	{
		mundo.Dibuja();
	}
	else if (estado == GAMEOVER)
	{
		//mundo.Dibuja();
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Presione -C- para continuar", -6, 15);
		glEnable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Textures/over.png").id);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(1, 0); glVertex3d(10, 14, 1);
		glTexCoord2d(1, 1); glVertex3d(10, 0, 1);
		glTexCoord2d(0, 1); glVertex3d(-10, 0, 1);
		glTexCoord2d(0, 0); glVertex3d(-10, 14, 1);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);
	}
	else if (estado == FIN)
	{
		mundo.Dibuja();
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!", 5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", 5, 9);
	}
	else if (estado == PAUSE)
	{
		mundo.Dibuja();
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("JUEGO PAUSADO", 6, mundo.escenario.p_ojo_y+2);
		ETSIDI::printxy("Presione -P- para continuar", 6, mundo.escenario.p_ojo_y);
		ETSIDI::printxy("Presione -S- para salir", 6, mundo.escenario.p_ojo_y-1);
	}
	else if (estado == TRANSICION)
	{
		//CODIGO PARA PINTAR UNA PANTALLA NEGRA CON LETRAS
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		glEnable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Textures/nextlevel.png").id);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(1, 0); glVertex3d(14, 18, 1);
		glTexCoord2d(1, 1); glVertex3d(14, -4, 1);
		glTexCoord2d(0, 1); glVertex3d(-15, -4, 1);
		glTexCoord2d(0, 0); glVertex3d(-15, 18, 1);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);
	}
}
