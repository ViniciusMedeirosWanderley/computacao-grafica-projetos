#include "main.h"

void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************



	tCor cor1 = {255,50,50,255};
	tCor cor2 = {50,255,50,255};
	tCor cor3 = {50,50,255,255};
	tCor cor4 = {255,255,255,255};
	Coordenadas * p0 = (struct Coordenadas *) malloc(sizeof(Coordenadas));
	Coordenadas * p1 = (struct Coordenadas *) malloc(sizeof(Coordenadas));
	Coordenadas * p2 = (struct Coordenadas *) malloc(sizeof(Coordenadas));
	Coordenadas * p3 = (struct Coordenadas *) malloc(sizeof(Coordenadas));
	PutPixel(250,250,&cor1);


	p0->coordenadaX = 50;
	p0->coordenadaY = 350;
	p1->coordenadaX = 200;
	p1->coordenadaY = 100;
	p2->coordenadaX = 350;
	p2->coordenadaY = 350;
	drawTriangle(p0,&cor3,p1,&cor2,p2,&cor1);
	p0->coordenadaX = 50;
	p0->coordenadaY = 360;
	p1->coordenadaX = 50;
	p1->coordenadaY = 500;
	p2->coordenadaX = 350;
	p2->coordenadaY = 500;
	p3->coordenadaX = 350;
	p3->coordenadaY = 360;
	drawQuad(p0,&cor3,p1,&cor2,p2,&cor1,p3,&cor4);

}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}
