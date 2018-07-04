#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 40
#define LETRA_INVALIDA 1
#define LETRA_MINUSCULA 2
#define NUMERO_INVALIDO 3
#define VAZIO 4
#define OK 5
#define CAR_INVALIDO 6
#define PONTMAX 120


void pegaCartas(char [],int,int*);

int main(){
	char cartas[MAX] = {'\0'};
	int points = 0;
	printf("Digite as cartas da rodada: ");
	pegaCartas(cartas,MAX,&points);
	printf("A pontuação foi de: %d\n",points);
	
	return 0;
}
int lelinha(char [],int);
int testaLinha(char []);
int computaPontos(char []);

void pegaCartas(char s[],int lim,int *points){
	int tam =0;
	int valido,vazio = 1;
	char linha[MAX];
	while(tam < 40 && vazio){
		lelinha(linha,MAX);
		switch((valido=testaLinha(linha))){
			case LETRA_INVALIDA:
					printf("Letra Invalida\n");
					break;
			case LETRA_MINUSCULA:
					printf("Letra Minuscula\n");
					break;
			case NUMERO_INVALIDO:
					printf("Numero Invalido\n");
					break;
			case CAR_INVALIDO:
					printf("Caracter Invalido\n");
					break;
			case VAZIO:
					vazio =0;
					break;
			case OK:
					*points += computaPontos(linha);
					tam++;
					break;
		}
		if (*points>PONTMAX){
			printf("Pontuação Maxima Excedida! Erro na Contagem\n");
			break;
		}
	}
}

int testaLinha(char linha[]){
	char letras[] = "AKJQakjq";
	char numeros[] = "765432";
	if (isalpha(linha[0])){
		if(!strchr(letras,linha[0]))
			return LETRA_INVALIDA;
		if(islower(linha[0]))
			return LETRA_MINUSCULA;
		return OK;
	}
	else if (isdigit(linha[0])){
		if (!strchr(numeros,linha[0]))
			return NUMERO_INVALIDO;
		return OK;
	}
	else if(linha[0] == '\n')
		return VAZIO;
	
	return CAR_INVALIDO;
}

int lelinha(char s[],int lim){
	int c, i;
	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

int computaPontos(char s[]){
	char ordem[]="A7KJQ65432";
	int pontos[]={11,10,4,3,2,0,0,0,0,0};
	int i;
	for(i=0;ordem[i]!=s[0];i++)
		;
	return pontos[i];
}
