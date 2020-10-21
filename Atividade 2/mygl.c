#include "mygl.h"

unsigned char* fb_ptr = NULL;

void InitMyGl(void) {
    fb_ptr = (unsigned char *)malloc(IMAGE_WIDTH * IMAGE_HEIGHT * 4 * sizeof(char));	

    for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT; ++i) {
        fb_ptr[i * 4] = 0;
        fb_ptr[i * 4 + 1] = 0;
        fb_ptr[i * 4 + 2] = 0;
        fb_ptr[i * 4 + 3] = 255;
    }    
}

unsigned char* GetFBMemPtr(void) {
	return fb_ptr;
}

void CloseMyGl(void) {
    if (!fb_ptr)
        free(fb_ptr);
}

//
// >>> Caro aluno: defina aqui as funções que você implementar <<<
//

void PutPixel(struct Ponto p, struct Cor c)		//Função para pintar pixel
{
	//Pela definição da fórmula vista em aula, calculamos o desvio do ponteiro no color buffer
	int desvio = p.x * 4 + p.y * 4 * IMAGE_WIDTH;

	fb_ptr[desvio] = c.r;		//Adiciona a informação da banda vermelha do pixel
	fb_ptr[desvio + 1] = c.g;	//Adiciona a informação da banda verde do pixel
	fb_ptr[desvio + 2] = c.b;	//Adiciona a informação da banda azul do pixel
	fb_ptr[desvio + 3] = c.a;	//Adiciona a informação da banda alfa do pixel
}

void DrawLine(struct Ponto p0, struct Ponto p1, struct Cor c0, struct Cor c1)	//Função para preencher linha
{
	//Declarando as coordenadas x e y inicial e final
	int x = p0.x;
	int y = p0.y;
	int xf = p1.x;
	int yf = p1.y;
	//Declarando uma cor para preemcher cada pixel da linha
	struct Cor c = c0;
	//Declarando auxiliares para x e y
	int aux_X;
	int aux_Y;
	//O valor dos auxiliares será calculado de acordo com os valores de delta x e delta y
	int dx = xf - x;
	
	if (dx < 0) {		//Para o caso do delta x dar um valor negativo, o auxiliar terá valor negativo
		dx *= -1;
		aux_X = -1;
	} else {			//caso contrário o auxiliar terá valor positivo
		aux_X = 1;
	}
	
	int dy = yf - y;
	
	if (dy < 0) {		//A mesma coisa feita no delta x será feita com o delta y
		dy *= -1;
		aux_Y = -1;
	} else {
		aux_Y = 1;
	}
	
	PutPixel(p0, c0);	//Para cada ponto na linha é utilizada a função PutPixel para colorir a cor de cada pixel
	
	//A sequência de código a seguir simula um rebatimento de qualquer linha para o primeiro octante
	if (dy <= dx){								//Coeficiente angular menor que 1
		int D = 2 * dy - dx;					//O D e os incrementos são calculados de acordo com o algoritmo visto em aula
		int inc_L = 2 * dy;
		int inc_NE = 2 * (dy - dx);
		
		//Cálculo dos deltas de cada banda utilizados para interpolar as cores
		float dr = (c1.r - c0.r)/dx;
		float dg = (c1.g - c0.g)/dx;
		float db = (c1.b - c0.b)/dx;
		
		//Loop no qual o cálculo dos pixel seguintes é feito
		while(x * aux_X < xf){		
			if (D <= 0){			//O ponto médio está acima da reta
				D += inc_L;			//Caminha para o pixel leste
				x = x + 1 * aux_X;	//O valor do x será incrementado ou decrementado de acordo com a posição da coordenada x final
			} else{					//O ponto médio está abaixo da reta
				D += inc_NE;		//Caminha para o pixel nordeste
				x = x + 1 * aux_X;	//O valor do x será incrementado ou decrementado de acordo com a posição da coordenada x final
				y = y + 1 * aux_Y;	//O valor do y será incrementado ou decrementado de acordo com a posição da coordenada y final
			}
			
			//Interpolação cor por cor
			c.r += dr;
			c.g += dg;
			c.b += db;
			
			//Um novo ponto é criado com as coordenadas previamente calculadas
			struct Ponto p = {x, y};
			//Colorindo o pixel correspondente a esse ponto
			PutPixel(p, c);
	 	}
	} else{										//Coeficiente angular maior que 1
		int D = 2 * dx - dy;					//É feito um processo semelhante ao anterior com a diferença de que nas funções
		int inc_L = 2 * dx;						//os valores de x e y e dx e dy tem posições invertidas
		int inc_NE = 2 * (dx - dy);
		
		float dr = (c1.r - c0.r)/dy;
		float dg = (c1.g - c0.g)/dy;
		float db = (c1.b - c0.b)/dy;
		
		while(y * aux_Y < yf){
			if (D <= 0){
				D += inc_L;
				y = y + 1 * aux_Y;
			} else{
				D += inc_NE;
				x = x + 1 * aux_X;
				y = y + 1 * aux_Y;
			}
			
			c.r += dr;
			c.g += dg;
			c.b += db;
			
			struct Ponto p = {x, y};
			
			PutPixel(p, c);
		}
	}
}

void DrawTriangle(struct Ponto p0, struct Ponto p1, struct Ponto p2, struct Cor c0, struct Cor c1, struct Cor c2)	//Desenha um triângulo
{
	//O triângulo é criado através da conjuntura de 3 linhas criadas utilizando a função DrawLine
	DrawLine(p0, p1, c0, c1);
	DrawLine(p1, p2, c1, c2);
	DrawLine(p2, p0, c2, c0);
}

// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void) {
    //
    // >>> Caro aluno: chame aqui as funções que você implementou <<<
    //
    
    //Inicialização de uma paleta de cores
    struct Cor vermelho = {255, 0, 0, 255};
    struct Cor verde = {0, 255, 0, 255};
    struct Cor azul = {0, 0, 255, 255};
    struct Cor ciano = {0, 255, 255, 255};
    struct Cor magenta = {255, 0, 255, 255};
    struct Cor amarelo = {255, 255, 0, 255};
    struct Cor branco = {255, 255, 255, 255};
    
    //Teste 1: Pinta um tabuleiro de xadrez
    /*{
    	//divisão dos intervalos das linhas
    	int l0 = IMAGE_HEIGHT/8;
    	int l1 = l0*2;
    	int l2 = l0*3;
    	int l3 = l0*4;
    	int l4 = l0*5;
    	int l5 = l0*6;
    	int l6 = l0*7;
    	
    	//divisão dos intervalos das colunas
    	int c0 = IMAGE_WIDTH/8;
    	int c1 = c0*2;
    	int c2 = c0*3;
    	int c3 = c0*4;
    	int c4 = c0*5;
    	int c5 = c0*6;
    	int c6 = c0*7;
    	
    	for (int i = 0; i < IMAGE_HEIGHT; i++){
    		for (int j = 0; j < IMAGE_WIDTH; j++){
    			struct Ponto p = {j, i};
    			if ((i < l0) && ((j < c0) || (j > c1 && j < c2) || (j > c3 && j < c4) || (j > c5 && j < c6))){
    				PutPixel(p, branco);
				}
    			if ((i > l0 && i < l1) && ((j > c0 && j < c1) || (j > c2 && j < c3) || (j > c4 && j < c5) || (j > c6))){
    				PutPixel(p, branco);
				}
				if ((i > l1 && i < l2) && ((j < c0) || (j > c1 && j < c2) || (j > c3 && j < c4) || (j > c5 && j < c6))){
    				PutPixel(p, branco);
				}
    			if ((i > l2 && i < l3) && ((j > c0 && j < c1) || (j > c2 && j < c3) || (j > c4 && j < c5) || (j > c6))){
    				PutPixel(p, branco);
				}
				if ((i > l3 && i < l4) && ((j < c0) || (j > c1 && j < c2) || (j > c3 && j < c4) || (j > c5 && j < c6))){
    				PutPixel(p, branco);
				}
    			if ((i > l4 && i < l5) && ((j > c0 && j < c1) || (j > c2 && j < c3) || (j > c4 && j < c5) || (j > c6))){
    				PutPixel(p, branco);
				}
				if ((i > l5 && i < l6) && ((j < c0) || (j > c1 && j < c2) || (j > c3 && j < c4) || (j > c5 && j < c6))){
    				PutPixel(p, branco);
				}
    			if ((i > l6) && ((j > c0 && j < c1) || (j > c2 && j < c3) || (j > c4 && j < c5) || (j > c6))){
    				PutPixel(p, branco);
				}
			}
		}
	}*/
	
	//Teste 2: Desenha um quadrado na tela de tamanho 500x500
	/*{
		struct Ponto A = {0, 0};
		struct Ponto B = {500, 0};
		struct Ponto C = {500, 500};
		struct Ponto D = {0, 500};
		
		DrawLine(A, B, branco, verde);
		DrawLine(B, C, verde, vermelho);
		DrawLine(C, D, vermelho, azul);
		DrawLine(D, A, azul, branco);
	}*/
	
	//Teste 3: Desenha um triângulo
	/*{
		struct Ponto A = {0, 0};
		struct Ponto B = {300, 500};
		struct Ponto C = {500, 300};
		
		DrawTriangle(A, B, C, ciano, magenta, amarelo);
	}*/
}
