#include "Escenario.h"
#include "Personaje.h"
#include "Enemigo.h"
#include "ListaEnemigos.h"
class Mundo
{
private: 
	Personaje personaje;
	ListaEnemigos enemigos;
	Escenario escenario;	
public:
	void Tecla(unsigned char key);
	void TeclaEspecial(bool izq=false, bool der=false);
	void Inicializa();
	void RotarOjo();
	void Mueve();
	void Dibuja();	
	float x_ojo;
	float y_ojo;
	float z_ojo;
};
