#include <stdio.h>
#include "counting.h"

void countingRadix(int *vetor, int tam, int d){
        int vetorS[tam];
        zera_vetor(vetorS,tam);
        int maior = ((vetor[0])/d)%10;
        for(int i=1; i<tam-1; i++){
                if((vetor[i]/d%10)> maior)
                        maior=vetor[i];
        }
        int vetorC[(maior+1)];
	zera_vetor(vetorC,(maior));
	
        for(int i=0;i<tam-1;i++){
                vetorC[((vetor[i]/d)%10)] +=1; //Coloca no vetor C as ocorrencias de cada valor
        }

        for(int i=1;i<maior;i++){
                vetorC[i]+=vetorC[i-1]; // Remove um do valor do indice, pra que seja alocado a esquerda do anterior
        }

        for(int i=0;i<tam-1;i++){
                vetorS[vetorC[(vetor[i]/d)%10]-1] = vetor[i] ;
		vetorC[(vetor[i]/d)%10]--;
}

        for(int i =0;i<tam-1;i++){
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
        RadixSort(vetor,21);

        for(int i =0;i<20-1;i++){
                printf("%d,",vetor[i]);
        }
        return 0;
}

