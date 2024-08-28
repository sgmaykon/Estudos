#include <stdio.h>
#include "counting.h"

void countingRadix(int *vetor, int tam, int d){
	int vetorS[tam];
	zera_vetor(vetorS,tam);
	int maior = ((vetor[0])/d)%10;
	for(int i=0; i<tam; i++){
		if(vetor[i]> maior)
			maior=vetor[i];
	}
	int vetorC[10]={0};

	for(int i=0;i<tam-1;i++){
                vetorC[((vetor[i]/d)%10)] +=1; //Coloca no vetor C as ocorrencias de cada valor
        }   

        for(int i=1;i<10;i++){
                vetorC[i]+=vetorC[i-1]; // Remove um do valor do indice, pra que seja alocado a esquerda do anterior
        }   

	for(int i=tam-1;i>=0;i--){
		vetorS[vetorC[(vetor[i]/d)%10]] =vetor[i] ;
		vetorC[(vetor[i]/d)%10]--;	
}

	for(int i =0;i<tam;i++){
		vetor[i]=vetorS[i];
	}

}

void RadixSort( int *vetor,int tam){
	int max =maior_valor(vetor,tam);
        int d=1;
	while(max/d>0){
		countingRadix(vetor,tam,d);
		d=d*10;
	}
}	
int main(){
	int vetor[20] = {29, 125, 391, 74, 213, 178, 43, 19, 424, 131, 120, 158, 105, 92, 169, 81, 1, 143, 210, 51};	
	RadixSort(vetor,20);

	for(int i =1;i<20;i++){
		printf("%d,",vetor[i]);
	}
	return 0;
}

