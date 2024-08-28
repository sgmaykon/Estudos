#include <stdio.h>

int mediana(int vetor[],int *vetor[],int *vetor[]){
	

}

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


	return 0;
}
