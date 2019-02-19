#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include <math.h>

//Primeiro para facilitar , vamos criar a estrutura da Cor e da Posição do Pixel

typedef struct Color{
  float red;
  float green;
  float blue;
  float alpha;
}tCor; 

typedef struct Coordenadas{
  int coordenadaX;
  int coordenadaY;
}tCoordenadas ; 

void PutPixel(int coordenadaX, int coordenadaY, tCor *cor){

  int byte = (coordenadaX* 4) + (coordenadaY * IMAGE_WIDTH * 4);
  FBptr[byte] = cor->red;
  FBptr[byte + 1] = cor->green;
  FBptr[byte + 2] = cor->blue;
  FBptr[byte + 3] = cor->alpha;

}

void DrawLineNoBresenham(Coordenadas * p0, Coordenadas * p1, Color * corInicial, Color * corFinal)
{
	int deltaX = p1->coordenadaX - p0->coordenadaX, 
	    deltaY = p1->coordenadaY - p0->coordenadaY,
	    ix = 1, iy = 1,
	    e,coordendaX, coordendaY,i;          

	Color * corAuxiliar = (struct Color *) malloc(sizeof(Color));
	corAuxiliar->red = corInicial->red;
	corAuxiliar->green = corInicial->green;
	corAuxiliar->blue = corInicial->blue;
	corAuxiliar->alpha = corInicial->alpha;

	if(deltaX < 0) ix = -ix;
	if(deltaY < 0) iy = -iy;

	deltaX = abs(deltaX);
	deltaY = abs(deltaY);

	float deltaR = (corFinal->red - corAuxiliar->red),
        deltaG = (corFinal->green - corAuxiliar->green),
        deltaB = (corFinal->blue - corAuxiliar->blue),
        deltaA = (corFinal->alpha - corAuxiliar->alpha);

	coordendaX = p0->coordenadaX;
	coordendaY = p0->coordenadaY;

	if (deltaX > deltaY) {
		e = (deltaY << 1) - deltaX;
		deltaR /= deltaX;
    	deltaG /= deltaX;
	    deltaB /= deltaX;
    	deltaA /= deltaX;

		for(i = 0; i < deltaX; i++) {

			corAuxiliar->red += deltaR;
			corAuxiliar->green += deltaG;
			corAuxiliar->blue += deltaB;
			corAuxiliar->alpha += deltaA;

			PutPixel(coordendaX,coordendaY,corAuxiliar);

			if(e < 0)
				e += deltaY << 1;
			else {
				coordendaY += iy;
				e += (deltaY - deltaX) << 1;
			}
			coordendaX += ix;
		}
	}
  else {
		e = (deltaX << 1) - deltaY;
		deltaR /= deltaY;
	    deltaG /= deltaY;
    	deltaB /= deltaY;
    	deltaA /= deltaY;

	    for(i = 0; i < deltaY; i++) {
				corAuxiliar->red += deltaR;
				corAuxiliar->green += deltaG;
				corAuxiliar->blue += deltaB;
				corAuxiliar->alpha += deltaA;

	      PutPixel(coordendaX,coordendaY,corAuxiliar);
	      if(e < 0)
	      e += deltaX << 1;
	      else {
	        coordendaX += ix;
	        e += (deltaX - deltaY) << 1;
	      }
			coordendaY += iy;
	    }
	}
}

void drawTriangle(Coordenadas * pontoInicial, Color * cor1, Coordenadas * pontoIntermediario, Color * cor2, Coordenadas * pontoFinal, Color * cor3) {
	DrawLineNoBresenham(pontoInicial,pontoIntermediario,cor1,cor2);
	DrawLineNoBresenham(pontoIntermediario,pontoFinal,cor2,cor3);
	DrawLineNoBresenham(pontoFinal,pontoInicial,cor3,cor1);
}

void drawQuad(Coordenadas * p0, Color * cor1, Coordenadas * p1, Color * cor2, Coordenadas * p2, Color * cor3, Coordenadas * p3, Color * cor4) {
	DrawLineNoBresenham(p0,p1,cor1,cor2);
	DrawLineNoBresenham(p1,p2,cor2,cor3);
	DrawLineNoBresenham(p2,p3,cor3,cor4);
  DrawLineNoBresenham(p3,p0,cor4,cor1);
}




#endif // _MYGL_H_
