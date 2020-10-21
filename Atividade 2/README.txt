DUPLA: 

JOHAN KEVIN ESTEVÃO DE FREITAS - 20170171741
GABRIEL FORMIGA BATISTA - 11503377

•Os objetivos desta atividade são:

	- Familiarizar os alunos com os algoritmos de rasterização utilizados em computação gráfica.


• Para o escopo dessa atividade desenvolvemos no cabeçado estruturas para representar um ponto (com suas coordenadas)
  assim como uma estrutura para representar cores (com valores floats para representar cores primarias e um int para alpha).

• Para as funções requiridas na atividade foi feito:

	-Para PutPixel foi utilizado a formula dada em aula para calcular Offset, em seguida, para cada ponto é atribuido
	 uma cor e posição de acordo com o escolhido. PutPixel é uma função que recebe (struct Ponto, struct Cor)
	
	-Para DrawLine foi feita uma função que recebe 2 pontos (inicial e final) e 2 cores (inicial e final, com a linha mudando
	 progressivamente de uma cor a outra). Em seguida, de acordo como é comentado no código, é calculado o Delta x e Delta y de acordo
	 com o que foi ensinado em aula. Valores auxiliares são usados para rebater a linha em casos do delta der negativo
	 Em seguida é calculado o D e os incrementos Leste e Nordeste. Por fim a linha é desenhada de acordo com o ensinado em aula.
	 (Comentários em código)

	-Por fim, para o DrawTriangle é utilizado três chamadas da função DrawLine para fechar o polígono. Essa função recebe
	 três pontos e três cores.

• Para testar foram feitas 3 imagens, uma para cada função

	-Para testar a PutPixel foi feito um tabuleiro de xadrez, onde a tela teve sua largura e comprimento dividido por 8 e
	 para cada um desses oito espaços, os pixels internos foram pintados de branco ou preto a fim de criar um xadrez.

	-Para testar a DrawLine é feito um quadrado de tamanho 500x500 de cores branco, verde, vermelho e azul.

	-Para testar a função DrawTriangle é desenhado um triangulo de cores ciano, magenta e amarelo.

• Todos os resultados devem ser encontrados juntos a esse README