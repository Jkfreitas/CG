DUPLA: 

JOHAN KEVIN ESTEV�O DE FREITAS - 20170171741
GABRIEL FORMIGA BATISTA - 11503377

�Os objetivos desta atividade s�o:

	- Verificar se o ambiente de desenvolvimento em OpenGL 3.3 est�a corretamente configurado nos
	computadores dos alunos;

	- Familizarizar os alunos com a estrutura de um programa OpenGL moderno.

� Utilizamos uma m�quina virtual para simular o ambiente linux com o UBUNTU 18.02 e ap�s instalar as blibliotecas seguindos os passos:

	sudo apt-get install freeglut3

	sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev

	sudo apt-get install libglew1.5-dev libglm-dev

� Ap�s isso, feito o download dos arquivos pelo link:

	- https://github.com/capagot/icg/tree/master/01_hello_world_gl/modern_opengl

� Geramos o executavel e compilamos, respectivamente usando:

	gcc main.c -o main.exe -lglut -lGL -lGLU -lm

	./main.exe

� O primeiro resultado, obteve um triangulo preto e branco ocasionado pelo erro mostrado na "Figura 01" e"Figura 02 - Erro''.

� Ent�o, utilizamos:

	MESA_GL_VERSION_OVERRIDE=3.3 MESA_GLSL_VERSION_OVERRIDE=330 ./main.exe

para a execu��o do programa obtendo o triangulo colorido com �xito ("Figura 03"), como mostrado na proposta da atividade.



