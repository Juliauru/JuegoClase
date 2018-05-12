#pragma once
#include "Transportable.h"
class Box:public Transportable
{
public:
	Box();
	~Box();
	void Dibuja();
	void CambiaEstado();
};

