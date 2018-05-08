#include "Plataforma.h"
#include "glut.h"
int Plataforma::n_plataformas = 7;
Plataforma::Plataforma(int l)
{
	if (l < 2) { //Hacer 
		
	}
	else {
		largo = l;
	}

	lado = 0.25;
	ancho = 2;
}

Plataforma::~Plataforma()
{
}
void Plataforma::Dibuja() {
	glColor3ub(color.rojo, color.verde, color.azul);
	glTranslatef(lado / 2, lado / 2, lado / 2);
	for (int i = 0; i <(largo / lado); i++) {
		glTranslatef(posicion.x + (lado*i), posicion.y, 0);
		for (int j = 0; j < (ancho / lado); j++) {
			glTranslatef(0, 0, (j*lado));
			glutSolidCube(lado);
			glTranslatef(0, 0, -(j*lado));
		}
		glTranslatef(-(posicion.x + (i*lado)), -posicion.y, 0);
	}
	glTranslatef(-lado / 2, -lado / 2, -lado / 2);

}
int Plataforma::get_nplataformas() {
	return n_plataformas;
}
void Plataforma::setLargo(int l) {
	if (l < 2) {
		largo = 2;
	}
	else {
		largo = l;
	}
}
float Plataforma::Distancia(Vector2D punto, Vector2D* direccion) {
	Vector2D u = (punto - posicion);
	Vector2D v = ((posicion+largo) - posicion).unitario();
	float longitud = largo;
	Vector2D dir;
	float valor = u * v;
	float distancia = 0;
	if (valor<0)
		dir = u;
	else if (valor>longitud)
		dir = (punto - (posicion+largo));
	else
		dir = u - v * valor;
	distancia = dir.modulo();
	if (direccion != 0) //si nos dan un vector…
		*direccion = dir.unitario();
	return distancia;
}