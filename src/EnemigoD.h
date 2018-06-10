#pragma once
#include "Enemigo.h"
using ETSIDI::SpriteSequence;
class EnemigoD :public Enemigo
{
private:
	SpriteSequence en2;
public:	
	EnemigoD(Vector pos);
	~EnemigoD();
	int EnemEliminado();
	void Dibuja();
};

