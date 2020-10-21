#ifndef MYGL_H
#define MYGL_H

#include <stdlib.h>
#include <string.h>

#include "core.h"

void InitMyGl(void); // Inicializa o frame buffer 
unsigned char* GetFBMemPtr(void); // Retorna o ponteiro do framebuffer buffer
void CloseMyGl(void); // Desaloca a mem�ria do framebuffer

// Declara��o da fun��o que chamar� as fun��es implementadas pelo aluno
void MyGlDraw(void);

//
// >>> Caro aluno: declare aqui as fun��es que voc� implementar <<<
//

//Defini��o de estruturas

//Ponto
struct Ponto
{
	int x;
	int y;
};

//Cor
struct Cor
{
	float r;
	float g;
	float b;
	int a;
};

//Declara��o das fun��es a serem implementadas
void PutPixel(struct Ponto p, struct Cor c);																		//cabe�alho do pixel
void DrawLine(struct Ponto p0, struct Ponto p1, struct Cor c0, struct Cor c1);										//cabe�alho das linhas
void DrawTriangle(struct Ponto p0, struct Ponto p1, struct Ponto p2, struct Cor c0, struct Cor c1, struct Cor c2);	//cabe�alho do tri�ngulo

#endif  // MYGL_H
