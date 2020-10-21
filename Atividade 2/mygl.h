#ifndef MYGL_H
#define MYGL_H

#include <stdlib.h>
#include <string.h>

#include "core.h"

void InitMyGl(void); // Inicializa o frame buffer 
unsigned char* GetFBMemPtr(void); // Retorna o ponteiro do framebuffer buffer
void CloseMyGl(void); // Desaloca a memória do framebuffer

// Declaração da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void);

//
// >>> Caro aluno: declare aqui as funções que você implementar <<<
//

//Definição de estruturas

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

//Declaração das funções a serem implementadas
void PutPixel(struct Ponto p, struct Cor c);																		//cabeçalho do pixel
void DrawLine(struct Ponto p0, struct Ponto p1, struct Cor c0, struct Cor c1);										//cabeçalho das linhas
void DrawTriangle(struct Ponto p0, struct Ponto p1, struct Ponto p2, struct Cor c0, struct Cor c1, struct Cor c2);	//cabeçalho do triângulo

#endif  // MYGL_H
