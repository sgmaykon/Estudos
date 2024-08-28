#include <stdio.h>
#define TAM 20
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
		indice =  vetor[i]/7;	//Descobrir para qual balde vai o valor.Esse metodo eh para inteiros.
		/* Ao dividir o valor, obtem-se um indice inteiro que sera usado como indice pro balde. Isso separa intervalos pros baldes*/  
		j = baldes[indice].qtd; //Necessario para nao pular enderecos nos vetores dentro dos baldes
		baldes[indice].valores[j]=vetor[i]; //Atribui ao balde, o valor do vetor
	        baldes[indice].qtd++;	//Aumenta a variavel que diz a quantidade de valores no balde
	}
	for(int i=0; i<TAM;i++){
		Quicksort(baldes[i].valores,0,baldes[i].qtd-1);  //Ordenacao feita usando Quicksort criado na atividade anterior
	}
	
	 int index=0; //Index para modificacao do vetor original
	 for(int i=0; i<TAM;i++){
			if( (baldes[i].valores[0]!=0) ){ //Verifica se o primeiro valor no balde e nulo. Caso nao seja,
				memcpy(vetor+index, baldes[i].valores, ((baldes[i].qtd ) * sizeof(double)) );  // Copia os dados de dentro do balde para o vetor
			index= index+baldes[i].qtd; //Soma ao indice a quantidade de elementos que tinham no balde
			}
		}
	 
	
}

int main(){
	double vetor[TAM] = {29, 12, 3, 7, 2, 17, 4, 19, 42, 31, 20, 15, 10, 9, 16, 8, 1, 13, 21, 5} ;
	bucketsort(vetor,TAM); //Chamada  do bucketsort
	for(int i=0;i<TAM;i++){
		printf("%lf, ", vetor[i]);
	}	
	return 0;
}
