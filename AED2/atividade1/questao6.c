#include <stdio.h>

void swap(int *vetor1,int *vetor2){  //primitiva de troca
	int aux=*vetor1;
	*vetor1=*vetor2;
	*vetor2=aux;
}

void ShellSort(int *vetor,int n){
	int gap =(2^n)-1; //Define um gap. Nesse caso, optei por 2^n-1
	while (gap > 0){ //Enquanto o gap for maior que 0, o que significa que ainda tem coisas coisas a serem ordenadas
		for (int i=gap;i<n;i++){
			int j=i;
			while(j>= gap && vetor[j-gap] > vetor[j]){ //Verifica qual a posicao correta para o pivo
				swap(&vetor[j],&vetor[j-gap]);
				j=j-gap;
			}
		}
	gap=gap/2; //Diminui o gap
}

}

		

int main(){
	int vetor[20]={29, 12, 3, 7, 2, 17, 4, 19, 42, 31, 20, 15, 10, 9, 16, 8, 1, 13, 21, 5};
	ShellSort(vetor,20);
	for (int i =0; i<20;i++)
                  printf(" %d ",vetor[i]);
          printf("]");	
	
	return 0;
}
