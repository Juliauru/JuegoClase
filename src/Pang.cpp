#include "CoordinadorPang.h"
#include "glut.h"

CoordinadorPang coordinador;
///Mundo mundo; En este color eliminadas para realizar la maquina de estados
//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void OnSpecialKeyboardDown(int key, int x, int y);
void OnSpecialKeyboardDown2(int key, int x, int y);

int main(int argc,char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MOXEY by Paula&Julia");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutSpecialFunc(OnSpecialKeyboardDown);
	glutSpecialUpFunc(OnSpecialKeyboardDown2);
	///mundo.Inicializa();
		
	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	

	return 0;   
}

void OnDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	///mundo.Dibuja();
	coordinador.Dibuja();
	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el c�digo de teclado
	///mundo.Tecla(key);
	coordinador.Tecla(key);

	glutPostRedisplay();
}
void OnSpecialKeyboardDown(int key, int x, int y)
{	
	bool izq = false, der = false, coge=false;
	switch (key)
	{
	case GLUT_KEY_LEFT:
		izq = true;
		break;

	case GLUT_KEY_RIGHT:
		der = true;
		break;
	case GLUT_KEY_UP:
		coge = true;
	}
	///mundo.TeclaEspecial(izq,der,coge);	
	coordinador.TeclaEspecial(izq,der,coge);
	glutPostRedisplay();
}
void OnTimer(int value)
{
	//poner aqui el c�digo de animacion
	///mundo.Mueve();
	coordinador.Mueve();
	//mundo.Mueve(izq, der);
	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}
void OnSpecialKeyboardDown2(int key, int x, int y) {
	//mundo.TeclaEspecial2(key);
	coordinador.TeclaEspecial2(key);
}