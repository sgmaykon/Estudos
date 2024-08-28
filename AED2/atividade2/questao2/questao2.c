#include <stdio.h>
#define TAM 8
#include <math.h>
#include "quicksort.h"
#include <stdlib.h>
#include <string.h>

typedef struct{
	int qtd;
	double valores[TAM];
}Balde;

void bucketsort(double *vetor,int tam){
	int indice;
	int j;

	/* Rotina pra inicializar os baldes vazios */
	Balde balde_default;
	balde_default.qtd=0;
	for(int i=0;i<tam;i++){
		balde_default.valores[i]=0;
	}	
	Balde baldes[TAM];
	for(int i=0;i<TAM;i++){
		baldes[i]=balde_default;
	}
	/* --------------------------------------- */

	for(int i =0; i<TAM;i++){
		indice = floor( (TAM-1)*vetor[i] );	//Descobrir para qual balde vai o valor. Usa-se n-1 para nao estourar o indice do vetor. Funciona para valores menores que 1.
		printf("\n DEBUG: FLOOR INDEX[%d]: %d \n", i,indice);
		j = baldes[indice].qtd;
		baldes[indice].valores[j]=vetor[i];
	        baldes[indice].qtd++;	//Guarda no balde certo o valor
	}
	for(int i=0; i<TAM;i++){
		Quicksort(baldes[i].valores,0,baldes[i].qtd-1);
	}
	

	 double* ordenado = malloc(sizeof (double) * TAM);
	 int index=0;
	 for(int i=0; i<TAM;i++){
			if( (baldes[i].valores[0]!=0) ){
				memcpy(ordenado+index, baldes[i].valores, ((baldes[i].qtd ) * sizeof(double)) ); 
			index= index+baldes[i].qtd;
			}
		}
	 
	 for(int i=0; i<TAM;i++){
		if(ordenado[i]!=0)
	 	vetor[i]=ordenado[i];	 
	}
}

int main(){
	double vetor[TAM] = {0.75,0.1,0.3,0.95,0.05,0.6,0.9,0.15}; 
	bucketsort(vetor,TAM);
	for(int i=0;i<TAM;i++){
		printf("%lf, ", vetor[i]);
	}	
	return 0;
}
