#pragma once
#include "Mundo.h"
class CoordinadorPang
{
public:
	CoordinadorPang();
	virtual ~CoordinadorPang();
	void TeclaEspecial(bool izq, bool der, bool coge);
	void TeclaEspecial2(unsigned char key);
	void Tecla(unsigned char key);
	void Mueve();
	void Dibuja();
protected:
	Mundo mundo;
	enum Estado{INICIO,JUEGO,GAMEOVER,FIN};
	Estado estado;
};

