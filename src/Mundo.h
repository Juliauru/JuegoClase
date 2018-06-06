#include "Escenario.h"
#include "Personaje.h"
#include "Enemigo.h"
#include "ListaEnemigos.h"
#include "Box.h"
#include "Llave.h"
#include "ListaCajas.h"
class Mundo
{
private: 
	Personaje personaje;
	ListaEnemigos enemigos;
		
	Llave llave;
	ListaCajas cajas;	
	int oportunidad;
	int nivel;
public:
	Escenario escenario;
	Mundo() {};
	bool GetOportunidad();
	void SetOportunidad(Personaje p);
	bool GetLlave();
	void Tecla(unsigned char key);
	void TeclaEspecial(bool izq=false, bool der=false,bool coge=false);
	void Inicializa();
	//void RotarOjo();
	void Mueve();
	void Dibuja();
	void Destruye();
	void TeclaEspecial2(unsigned char key);
	bool CargarNivel();
	};
