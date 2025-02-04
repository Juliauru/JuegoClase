#include "Movil.h"
#include "Constantes.h"
#include <math.h>

Movil::Movil(Vector pos, Vector vel, Vector ac, float l) :Objeto(pos),
																Long_caracteristica(l),
																velocidad(vel), 
																aceleracion(ac)
{

	posinicial=0;
	vinicial=0;
}

Movil::~Movil()
{
}
void Movil::Mueve(float t) { //Movimiento general de todos los objetos m�viles
	if(vinicial*vinicial + 2 * aceleracion.y*(posicion.y - posinicial)>0){ 
		velocidad.y = sqrt(vinicial*vinicial + 2 * aceleracion.y*(posicion.y - posinicial));
		posicion = posicion + velocidad*t;		
	}
	
	else {
		vinicial = 0;
		posinicial = 0;
		posicion = posicion + velocidad * t + aceleracion * (0.5f*t*t);
		velocidad = velocidad + aceleracion * t;
	}
}
void Movil::SetVel(float vx, float vy)
{

	velocidad.x = vx;
	velocidad.y = vy;
	
}
Vector& Movil::getVelocidad() {
	return velocidad;
}
Vector& Movil::getAceleracion() {
	return aceleracion;
}
float Movil::get_LCaract() {
	return Long_caracteristica;
}
float Movil::Distancia(Vector centro, Vector *direccion) {
	Vector dir = (posicion - centro).unitario();
	float distancia = (posicion - centro).modulo();
	*direccion = dir;
	return distancia;
}
void Movil::Rebote_escenario(float &posOJO, float xmax, float xmin) { //Funciones polim�rficas de m�s alto nivel
	if (posicion.x >= xmax) posicion.x = xmax;
	if (posicion.x <= xmin) posicion.x = xmin;
}
float Movil::Rebote_plat(float dis, float xmax, float xmin) {
	float dif = dis - Long_caracteristica;
	return dif;
}
