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
		if (key == 'e')
		{
			mundo.Inicializa();
			estado = JUEGO;
		}
		if (key == 's')
			exit(0);
	}
	else if (estado == JUEGO)
	{
		mundo.Tecla(key);
	}
	else if (estado == GAMEOVER)
	{
		if (key == 'c')
			estado = INICIO;
	}
	else if (estado == FIN)
	{
		if (key == 'c')
			estado = INICIO;
	}
}

void CoordinadorPang::Mueve()
{
	if (estado == JUEGO)
	{
		mundo.Mueve();
		if (mundo.GetOportunidad())
		{
			estado = GAMEOVER;
		}
		//if(//mundo.GetNivel())
		//{
		//	estado = FIN;
		//}
	}
}


void CoordinadorPang::Dibuja()
{
	////PRUEBITA LETRAS
	//ETSIDI::setTextColor(1, 1, 0);
	//ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	//ETSIDI::printxy("Pang 1.1", 4, 5);

	if (estado == INICIO) {
		//CODIGO PARA PINTAR UNA PANTALLA NEGRA CON LETRAS
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Pang 1.1", -5, 8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6);
		ETSIDI::printxy("Paula y Julia", 2, 1);
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
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Has perdido", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
	}
	else if (estado == FIN)
	{
		mundo.Dibuja();
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 9);
	}
}
