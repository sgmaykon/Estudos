//Algoritmo QuickSort

//Maykon dos Santos Gonçalves - 821653

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SWAP(x1,x2) {aux = x1; x1 = x2; x2 = aux;} //primitiva de troca
						   
//Para obter valor medio do vetor
#define MEDIANA(x1,x2,x3) {\
	if(x1>x2 && x1< x3)\
		medio=x1; \
	if(x2>x1 && x2<x3)\
		medio=x2;\
	else\
		medio=x3;\
}

#define PARTICAO(vetor,primeiro,ultimo){\
	MEDIANA(primeiro,ultimo,vetor[(sizeof(vetor)/sizeof(vetor[0]))/2]); i=primeiro-1; /*Para obter o valor medio*/ \
	\
	for (j=primeiro;j!= ultimo-1) {\
		if vetor[j] <=x{\
			i=i+1; SWAP(vetor[i],vetor[j];


}
void quicksort(int vetor, int primeiro, int ultimo){
	if (primeiro<ultimo){
		int q= PARTICAO(vetor,primeiro,ultimo);
		quicksort(vetor,primeiro, q-1);
	        quicksort(vetor,q+1,ultimo);
		}
	}

			
int main() {
	//int vetor[10]= {7,-1,54,12,5,7,1,4,100,-3};
	//int tam = sizeof(*vetor,vetor[0]);
	int a =6;
	int b=22;
	int c =20;
	int medio;
	MEDIANA(a,b,c);
	printf("o valor medio eh : %d \n ", medio);


	//for(int i= 0; i<tam/2; i++){

	//}

return 0;
}
