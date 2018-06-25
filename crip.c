#include <stdio.h>
#include <string.h>
#define N 29
#define MAX 50
#define FALSE 0
#define TRUE 1

void letrasMaiusculas(char[],int);
void eliminaRepetidas(char[],int);
void completaChave(char[],int);
void criaCripto(char[],char[],char[],int);

int main(){
 char frase[MAX];
 char chave[MAX];
 printf("Frase que origina a chave: ");
 fgets(chave,MAX,stdin);
 chave[strlen(chave)-1] = '\0';
 letrasMaiusculas(chave,MAX);
 eliminaRepetidas(chave,N);
 completaChave(chave,N);
 
 printf("Frase para ser criptografada: ");
 fgets(frase,MAX,stdin);
 frase[strlen(frase)-1] = '\0';
 letrasMaiusculas(frase,MAX);
 char cripto[N];
 criaCripto(cripto,chave,frase,N);
 printf("%s\n",cripto);
 return 0;
}

void letrasMaiusculas(char v[],int n){
 int i= 0;
 for (i= 0; i<n; i++){
	if ((v[i]>= 'a') && (v[i]<='z'))
		v[i] = v[i] + 'A' -'a';
 }
}

void eliminaRepetidas(char v[],int n){
  char chave[n];
  int  i=0,j =0,tam =1;
  int contem = FALSE;

  for (i = 0; i<n; i++){
	 contem = FALSE;
	 if((!(((v[i] >='A') && (v[i] <='Z'))||(v[i] ==',')||(v[i] == '.')||(v[i] == ' ')))) 
	 		continue;							/* elimina caracteres invalidos */
	 for (j= 0; j<tam-1;j++){
		if (chave[j] == v[i]){
			contem = TRUE;
			break;
		}	
		else
			contem = FALSE;
	 }
	 if (!contem){
		chave[tam-1] = v[i];
		tam++;
	 }
  }
  chave[tam-1] = '\0';
  strcpy(v, chave); 
}

void completaChave(char v[],int n){
  char alpha[N] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ,. "};
  char chave[n];
  int tam = 0;
  int i=0;
  for (i = 0; i<n && v[i] != '\0'; i++){
	chave[i] = v[i];
	tam++;
  }
	 
  int contem = FALSE;  
  int j = 0;
  for (i=0; i<n; i++){
	for (j= 0; j<n && v[j] != '\0';j++){
	  if (v[j] == alpha[i]){
		contem = TRUE;
		break;
	  }	
	  else
		contem = FALSE;
	}
     if (!contem){
	   	chave[tam++] = alpha[i];
	}
  }
  chave[n] = '\0';  
  strcpy(v, chave);
}

void criaCripto(char cripto[],char chave[],char frase[],int n){
  char alpha[N] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ,. "};
  int id = 0;
  int i=0,j=0;

  for (i = 0; i<n && frase[i] !='\0';i++){
	 for (j = 0; j<n;j++)
	 	if (alpha[j] == frase[i])
	 		break;
	 if ((id += j+1) >= n)
	 	id = id-n;
	 cripto[i] = chave[id];
  }
  cripto[i] = '\0';	
}








		 

