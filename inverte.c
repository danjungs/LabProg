#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXSIZE 40
#define SIZE 200
#define ERRO 0

int getLinha(char[],int);
void inverte(char[],int);
void imprime(char[],int);

int main()
{
    char linha[SIZE];
    if(getLinha(linha,SIZE)-1>MAXSIZE){
        printf("Frase muito grande\n");
        linha[MAXSIZE] = '\0';
    }
    inverte(linha,MAXSIZE);
    imprime(linha,MAXSIZE);
    return 0;
}

int valido(char[],int);
void swap(char [],int,int);

int getLinha(char s[],int size){
    int c, i;
    i = 0;
    while (--size > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = '\0';
    s[i] = '\0';
    return i;
}

void inverte(char s[],int size){
   char palavra[SIZE];
   int i=0,j=0,k,b,p=0;
   while(s[i]){
      j=i;
      p=0;
	  if(s[j]== ' '){
		  j++;
		  i++;
		  }
      while(s[j]!=' ' && s[j]!='\0'){
        palavra[p] = s[j];
        j++;
        p++;
      }
      palavra[p]= '\0';
      if(valido(palavra,SIZE)){
          for(b=i,k=j-1;b<k;b++,k--){
              swap(s,b,k);
          }
      }
    i =j; 
   }
}
void imprime(char s[],int size){
    int n=0,i=0;
   while(s[i]){
       if(s[i] == ' '){
           n++;
       }
       if(n==5){
           printf("\n");
           i++;
           n=0;
       }
       printf("%c",s[i++]);
   } 
   printf("\n");
}

void swap(char s[],int b, int k){
    char temp = s[b];
    s[b] = s[k];
    s[k] = temp;
}

int valido(char s[],int size){
    int i=0;
    while(s[i]){
        if(isdigit(s[i]))
            return ERRO;
        i++;
    }
    return i;
}



