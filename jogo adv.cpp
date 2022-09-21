#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main() {

	setlocale(LC_ALL, "portuguese");

	printf("          P  /_\\  P                              \n");
	printf("         /_\\_|-|-/_\\                            \n");
	printf("     n_n | ||. .|| | n_n       Bem vindo ao       \n");
	printf("     |_|_|nnnn nnnn|_|_|      Jogo de Advinhação! \n");
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
	 
		printf("Qual é o nível de dificuldade?\n");
		printf("(1) Fácil (2) Médio (3) Difícil (4) Master (5)Pica\n\n");
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
		printf("Chute um número: ");
		scanf("%d", &chute);
	
		if(chute < 0) {
		printf("Você não pode chutar números negativos\n");
		i--;
		continue;
		}
	
		if (chute==numerosecreto){
		printf("você acertou...sorte\n\n");
		break;
		}
	
		else{
		printf("você errou, tente novamente\n\n");
		}
		if (i==totaldetentativas){
		printf("você errou, e perdeu todas as tentativas ;-;");
		}
	
	
		acertou = chute == numerosecreto;
	
	
		if (acertou) {
		break;
		} else if (chute > numerosecreto) {
		printf("\nSeu chute foi maior do que o número secreto!\n\n");
		} else {
		printf("\nSeu chute foi menor do que o número secreto!\n\n");
		}
	
		double pontosperdidos = abs(chute - numerosecreto) / 2.0;
		pontos = pontos - pontosperdidos;
		}
		printf("Continuar jogando? (sim - não)\n");
			scanf(" %c", &continuar);
			system("cls");
	} while (continuar == 'sim');
	
	
}
			
	
	
	
	
	
	
