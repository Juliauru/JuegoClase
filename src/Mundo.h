#include "Escenario.h"
#include "Personaje.h"
class Mundo
{
private: 
	Personaje personaje;
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
