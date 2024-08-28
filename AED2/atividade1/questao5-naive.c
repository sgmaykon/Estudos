#include <stdio.h>

int particaoUltimoElemento(int *vetor,int primeiro,int ultimo){
	int x = vetor[ultimo]; //Definindo o ultimo elemento como pivo
	int i = primeiro-1;
	int aux=0;
	for (int j=primeiro; j<= ultimo-1;j++){ //Para percorrer o vetor
		if (vetor[j] <= x){
			i=i+1; //aumenta o indice do lado esquerdo
			aux=vetor[i]; vetor[i]=vetor[j]; vetor[j]=aux;
		}
	}
	aux = vetor[i + 1];
        vetor[i + 1] = vetor[ultimo];
        vetor[ultimo] = aux;
	return i+1;
}

void Quicksort(int *vetor,int  primeiro, int ultimo){
	if (primeiro < ultimo){
		int q = particaoUltimoElemento(vetor,primeiro,ultimo);
		Quicksort(vetor,primeiro,q-1); //Ordena o lado direito
		Quicksort(vetor,q+1,ultimo);
	}
}
		
int main(){
	int vetor[20] = {29, 12, 3, 7, 2, 17, 4, 19, 42, 31, 20, 15, 10, 9, 16, 8, 1, 13, 21, 5};
	Quicksort(vetor,0,19);
	printf("[");
	for (int i =0; i<20;i++)
		printf(" %d ",vetor[i]);
	printf("]");
	return 0;

}
