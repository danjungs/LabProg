#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define C_LUZ 299792458 //m/s
#define E_ELETRON 1.602176487e-19 //C
#define H_PLANK 6.62606896e-34 //J.s
#define P_VACUO 8.854187817e-12 //F/m
#define ALFA ((E_ELETRON*E_ELETRON)/(2*P_VACUO*H_PLANK*C_LUZ))
#define MAXLINE 100
#define ERRO 0


void maiuscula(char[],int);
int valida(char[],int);
double pegaNumero(char[]);
char pegaLetra(char[]);
void pegaLinha(char [], int) ;
double calculaAlfa(double,double,double,double);

int main(){
	char linha[MAXLINE];
	char letra;
	double constante,alfa;
	pegaLinha(linha,MAXLINE);
	maiuscula(linha,MAXLINE);
	if(valida(linha,MAXLINE)){
		constante = pegaNumero(linha);
		
		switch(letra=pegaLetra(linha)){
			case 'C':	alfa= calculaAlfa(constante,E_ELETRON,H_PLANK,P_VACUO);
							break;
			case 'E':	alfa= calculaAlfa(C_LUZ,constante,H_PLANK,P_VACUO);
							break;
			case 'H':	alfa= calculaAlfa(C_LUZ,E_ELETRON,constante,P_VACUO);
							break;
			case 'P':	alfa= calculaAlfa(C_LUZ,E_ELETRON,H_PLANK,constante);
							break;
			default:		printf("Letra Invalida\n");
		}
		printf("O valor de alfa =      %12.10e e 1/alfa = %12.10e\n",alfa,1/alfa);
		printf("O valor real de alfa = %12.10e e 1/alfa = %12.10e\n",ALFA,1/ALFA);
	}
	return 0;
}

void pegaLinha(char s[], int lim){
	int c, i=0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
}

void maiuscula(char s[],int lim){
	int i=0;
	for (i=0;s[i]!='\0';i++)
		s[i] = toupper(s[i]);	
}

int valida(char s[],int lim){
	int i=0;
	/* testa se é numero ou ponto*/
	if(!isdigit(s[i]) && s[i]!='.')
		return ERRO;
	
	/* passa pelos numeros */
	while(isdigit(s[++i]))
		;
	if(s[i] == '.' || s[i] == ','){
		i++;	
		while(isdigit(s[++i]))
			;
	}
	if (s[i]=='E'){
		// testa se o expoente tem sinal
		if (s[++i]=='-' || s[i]=='+') 
			i++; //pula sinal.
		if (isdigit(s[i])) 
			   while (isdigit (s[++i]))
			       ;
		else // se não for sinal nem dígito, depois de "E", é erro.
			return ERRO;
	}
	
	if(s[i++] != ' ')
		return ERRO;
	
	switch(s[i]){
			case 'C':	
			case 'E':	
			case 'H':	
			case 'P':	
							return i++;
						break;	
			default:		return ERRO;
	}
}

char pegaLetra(char s[]){
	int i;
	char c;
	for (i=0;isdigit(c=s[i])||c=='.' || c=='E'||c=='-' || c=='+';i++)
		;
	return s[++i];
}

double pegaNumero(char s[]){
	double val, ele=1, power;
	int i, sign;
	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	val = sign * val / power;
	if(s[i] == 'E'){
		i++;
		sign = (s[i] == '-') ? -1 : 1;
		if (s[i] == '+' || s[i] == '-')
			i++;
		for (ele = 0.0; isdigit(s[i]); i++)
			ele = 10.0 * ele + (s[i] - '0');
		return val*pow(10,sign*ele);
	}
	return val;
}

double calculaAlfa(double C,double E,double H,double P){
	return ((E*E)/(2*P*H*C));
}





















