DUPLA: 

JOHAN KEVIN ESTEV�O DE FREITAS - 20170171741
GABRIEL FORMIGA BATISTA - 11503377

�Os objetivos desta atividade s�o:

	- Familiarizar os alunos com os algoritmos de rasteriza��o utilizados em computa��o gr�fica.


� Para o escopo dessa atividade desenvolvemos no cabe�ado estruturas para representar um ponto (com suas coordenadas)
  assim como uma estrutura para representar cores (com valores floats para representar cores primarias e um int para alpha).

� Para as fun��es requiridas na atividade foi feito:

	-Para PutPixel foi utilizado a formula dada em aula para calcular Offset, em seguida, para cada ponto � atribuido
	 uma cor e posi��o de acordo com o escolhido. PutPixel � uma fun��o que recebe (struct Ponto, struct Cor)
	
	-Para DrawLine foi feita uma fun��o que recebe 2 pontos (inicial e final) e 2 cores (inicial e final, com a linha mudando
	 progressivamente de uma cor a outra). Em seguida, de acordo como � comentado no c�digo, � calculado o Delta x e Delta y de acordo
	 com o que foi ensinado em aula. Valores auxiliares s�o usados para rebater a linha em casos do delta der negativo
	 Em seguida � calculado o D e os incrementos Leste e Nordeste. Por fim a linha � desenhada de acordo com o ensinado em aula.
	 (Coment�rios em c�digo)

	-Por fim, para o DrawTriangle � utilizado tr�s chamadas da fun��o DrawLine para fechar o pol�gono. Essa fun��o recebe
	 tr�s pontos e tr�s cores.

� Para testar foram feitas 3 imagens, uma para cada fun��o

	-Para testar a PutPixel foi feito um tabuleiro de xadrez, onde a tela teve sua largura e comprimento dividido por 8 e
	 para cada um desses oito espa�os, os pixels internos foram pintados de branco ou preto a fim de criar um xadrez.

	-Para testar a DrawLine � feito um quadrado de tamanho 500x500 de cores branco, verde, vermelho e azul.

	-Para testar a fun��o DrawTriangle � desenhado um triangulo de cores ciano, magenta e amarelo.

� Todos os resultados devem ser encontrados juntos a esse README