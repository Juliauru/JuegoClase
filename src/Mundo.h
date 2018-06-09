#include "Escenario.h"
#include "Personaje.h"
#include "Enemigo.h"
#include "ListaEnemigos.h"
#include "Box.h"
#include "Llave.h"
#include "ListaCajas.h"
#include <time.h>
class Mundo
{
private: 
	Personaje personaje;
	ListaEnemigos enemigos;
	char *fich;
	Llave llave;
	ListaCajas cajas;	
	int oportunidad;
	int nivel;
	int texto;
	time_t tiempo;
public:
	Escenario escenario;
	Mundo() { texto = 0; };
	bool GetOportunidad();
	void SetOportunidad(Personaje p);
	bool GetLlave();
	void Tecla(unsigned char key);
	void TeclaEspecial(bool izq=false, bool der=false,bool coge=false);
	void Inicializa();
	void Mueve();
	void Dibuja();
	void Destruye();
	void TeclaEspecial2(unsigned char key);
	bool CargarNivel();
	void DibujaFrase(int num, float y, float inc);
	};
