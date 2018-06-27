#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 10000
#define TAM 26

int  getlinha(char[],int[],int);
void imprime(int,int [],int,char[]);
void sort(int[],char[],int);

int main(){
	char linha[MAX];
	int alpha[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	char alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int caracters =0;
	caracters =getlinha(linha,alpha,MAX);
	sort(alpha,alfabeto,TAM);
	imprime(caracters,alpha,TAM,alfabeto);
	return 0;
}

void alphabeto(char,int []);
char maiuscula(char);

int getlinha(char s[],int alfa[], int lim) {
	int c, i;
	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF){
		s[i++] = c;
		alphabeto(maiuscula(c),alfa);
	}
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return --i;
}

char maiuscula(char s){
	return toupper(s);	
}

void alphabeto(char letra,int alpha[]){
	int id = 0;
	if(isalpha(letra)){
		id = letra - 'A';
		alpha[id]++; 
	}
}

void swap(int s[],int x, int y)
{ 
    int temp = s[x];
    s[x] = s[y];
    s[y] = temp;
}

void swapchar(char s[],int x, int y)
{
    char temp = s[x];
    s[x] = s[y];
    s[y] = temp;
}

void sort(int alfa[],char alfabeto[],int n){
   int i, j=0;
   for (i = 0; i < n-1; i++)        
       for (j = 0; j < n-i-1; j++)
           if (alfa[j] < alfa[j+1]){
              swap(alfa,j,j+1);
              swapchar(alfabeto,j,j+1);
			  }
}


void imprime(int car,int alpha[],int n,char alfabeto[]){
	
	printf("Esse texto tem %d caracteres.\n",car);
	for(int i=0;i<n;i++){
		printf("%2c: ",alfabeto[i]);
		printf("%2d\n",alpha[i]);
	}
	printf("\n");

}
