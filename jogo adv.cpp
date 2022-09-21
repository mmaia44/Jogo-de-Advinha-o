#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main() {

	setlocale(LC_ALL, "portuguese");

	printf("          P  /_\\  P                              \n");
	printf("         /_\\_|-|-/_\\                            \n");
	printf("     n_n | ||. .|| | n_n       Bem vindo ao       \n");
	printf("     |_|_|nnnn nnnn|_|_|      Jogo de Advinha��o! \n");
	printf("    |\" \"  |  |_|  |\"  \" |                     \n");
	printf("    |_____| ' _ ' |_____|                         \n");
	printf("          \\__|_|___/                             \n");
	printf("\n");
	
	int chute;
	int acertou;
	int nivel;
	int totaldetentativas;
	char continuar = 'sim';
	
	double pontos = 1000;
		
	srand(time(0));	
	int numerosecreto = rand() % 100;
	
	do 
	{
	 
		printf("Qual � o n�vel de dificuldade?\n");
		printf("(1) F�cil (2) M�dio (3) Dif�cil (4) Master (5)Pica\n\n");
		printf("Escolha: ");
	
		scanf("%d", &nivel);
	
		switch(nivel) {
		case 1:
			totaldetentativas = 20;
			break;
		case 2:
			totaldetentativas = 15;
			break;
		case 3:
			totaldetentativas = 10;
			break;
		case 4:
			totaldetentativas = 5;
			break;
		default:
			totaldetentativas = 3;
		}
	
		for (int i = 1;i<=totaldetentativas; i++) {
	
		printf("-> Tentativa %d de %d\n", i, totaldetentativas);
		printf("Chute um n�mero: ");
		scanf("%d", &chute);
	
		if(chute < 0) {
		printf("Voc� n�o pode chutar n�meros negativos\n");
		i--;
		continue;
		}
	
		if (chute==numerosecreto){
		printf("voc� acertou...sorte\n\n");
		break;
		}
	
		else{
		printf("voc� errou, tente novamente\n\n");
		}
		if (i==totaldetentativas){
		printf("voc� errou, e perdeu todas as tentativas ;-;");
		}
	
	
		acertou = chute == numerosecreto;
	
	
		if (acertou) {
		break;
		} else if (chute > numerosecreto) {
		printf("\nSeu chute foi maior do que o n�mero secreto!\n\n");
		} else {
		printf("\nSeu chute foi menor do que o n�mero secreto!\n\n");
		}
	
		double pontosperdidos = abs(chute - numerosecreto) / 2.0;
		pontos = pontos - pontosperdidos;
		}
		printf("Continuar jogando? (sim - n�o)\n");
			scanf(" %c", &continuar);
			system("cls");
	} while (continuar == 'sim');
	
	
}
			
	
	
	
	
	
	
