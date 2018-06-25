#include <stdio.h>
#include <string.h>
#define SIZE 10
#define FALSE 0
#define TRUE 1

int  validade(char [],int);
void testaISBN(char[],int);
void atoi(char[],int);
void concertaISBN(char[],int);

int main(){ 
	char isbn[] = "?467885421";
	//testaISBN(isbn,SIZE);
	concertaISBN(isbn,SIZE);
	return 0;
}

int validade(char v[],int n){
	char val[] = "0123456789";
	int i;
	if (strlen(v) == n){
		for(i =0; i<n; i++){
			if((i ==n-1)&&(v[i] =='X'))
				continue;
			if(strchr(val,v[i])==NULL)
				break;
		}
		if (i == n)
			return TRUE;
	}
	return FALSE;
}

void atoi(char v[],int n){
	int i = 0;
	for(i =0;i<n;i++){
		v[i] = v[i] - '0';
	}
}


//printf("%d\n",validade("54678",SIZE));
//printf("%d\n",i);

void testaISBN(char v[],int n){
	int soma = 0;
	if(validade(v,n)){
		atoi(v,n);
		for(int i =10;i>0;i--){
			if (v[i] == 'X'){
				soma+=10;
				continue;
			}
			soma += v[n-i]*i;
		}
	   if(!(soma%11))
	   	printf("ISBN valido\n");
	   else
	   	printf("ISBN Invalido\n");
	}
	else
		printf("ISBN Invalido\n");
}


void concertaISBN(char v[],int n){
	int soma = 0;
	int j = 0;
	int id = strcspn(v,"?");
	atoi(v,n);
	if(id != 10){
		for(int i =10;i>0;i--){
			if (v[n-i] == 'X'){
				soma+=10;
				continue;
			}
			if (v[n-i] == '?'-'0')
				continue;		
			soma += v[n-i]*i;
		}
		for(j = 0; j<=n;j++){
			if(!((soma+(n-id)*j)%11))
				break;
		}
		v[id] =j;
		if(v[id] == 10)
			v[id] = 'X';
	}
	for (int i = 0;i<n;i++)
		printf("%d",v[i]);
	printf("\n");
}







