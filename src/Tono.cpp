#include "Tono.h"
//Ya no es util, pero existe por si no se meten texturas


Tono::Tono()
{
	rojo = 40;
	verde = 0;
	azul = 60;
}


Tono::~Tono()
{
}

void Tono::SetColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo = r;
	verde = v;
	azul = a;
}
