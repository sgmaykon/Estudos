/*
  5. O problema de Josephus: Trata-se de um problema conhecido na Matemática onde o objetivo é
encontrar o sobrevivente num grupo de soldados que vão se matando de pulos em pulos. Tal
problema pode ser descrito como: num grupo de n soldados que se matam de k em k, qual deles será
o sobrevivente? Desenvolva um algoritmo recursivo para resolver o problema de Josephus.
Explique seu raciocínio e o funcionamento do algoritmo.

*/



// Toma n pessoas, k =2
// Caso de parada: quando tem só uma pessoa viva 
// comecei o algoritmo:  
/* 
 Dado n =9 k=3;
 viva? pessoa[0] = mata(3)
 viva? pessoa[1] = mata (4)
 viva? pessoas [2] (mata(5)
 viva? n�o
 viva? nao
 viva? nao
 viva? pessoa[6] = mata[9]
 viva? pessoa[7] = mata[0]
 viva? pessoa[1] = mata[]
 viva? nao
 viva? nao


 viva? pessoa[0]
 
 *
*/


#include <stdio.h>
#include <stdlib.h>
#define TAM 4

//fun�ao para marcar todos as pessos como vivas
int* vida(int *vetor, int tam){
	for(int i=0; i<tam;i++)
		vetor[i]=1;
	return vetor;
}


int sobrevivente(int *pessoas,int tam,int k,int indice,int vivos,int posicao){
		if (vivos==1)
			return posicao;
		if (pessoas[indice]!=0){
			if(indice+k>tam){          //A pessoa está viva, e pode matar outra
				if(pessoas[(indice+k)-tam]!=0){
					pessoas[((indice+k)-tam)] =0;
					posicao=indice;
					sobrevivente(pessoas,tam,k,(indice+1)%tam,vivos-1,posicao);
				}
				else {
					 sobrevivente(pessoas, tam, k+1,indice,vivos,posicao);  //Pilha para encontrar o proximo vivo
				}
			}
			else{
				if(pessoas[indice+k]!=0){
					pessoas[indice+k]=0;
					posicao=indice;
					sobrevivente(pessoas,tam,k,(indice+1)%tam,vivos-1,posicao);	//Avan�a o indice
				}
				else{
					sobrevivente(pessoas,tam,k+1,indice,vivos,posicao);
										 // proxima pessoa viva
				}	
			}	
		}
		else{
			sobrevivente(pessoas,tam,k,(indice+1)%tam,vivos,posicao);
		}
}



int main(){

	int pessoas[TAM];
	vida(pessoas,TAM);
	//int k = rand() % TAM;
	int k = 3;
	printf("\n%d\n",sobrevivente(pessoas,TAM,k,0,TAM,0));
	
	return 0;

}
