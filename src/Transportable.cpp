#include "Transportable.h"



Transportable::Transportable(Vector pos, float l):Movil(pos, { 0.0f,0.0f }, { 0.0f,-3.0f}, l)
{}


Transportable::~Transportable()
{
}

void Transportable::CambiaEstado() //Cambia de estar libre a estar controlada por el personaje y al rev�s
{
		if (trans == true) trans = false;
		else trans = true;
}


