#include <stdio.h>

int busca(int *vetor,int elemento,int tam){
	for(int i=0; i< tam;i++){
		if (vetor[i] ==elemento)
			return i;
		}
	return -1;
}

void imprimeVetor(int *vetor, int tam){
	for(int i =0; i<tam; i++)
		printf("%d,", vetor[i]);
      printf("\n");
}      

int contaInversoes(int *vetor,int *vetor2,int n){
	int indice =0;
	int inversoes=0; 
        int i =0;
	int aux = 0;
	while (vetor[i]!=vetor2[i]){
		if(vetor[i]==vetor2[n-1]){
			for(int j=n-1; j>i;j--){
				aux = vetor2[j];
				vetor2[j]=vetor2[j-1];
				vetor2[j-1] = aux;
				inversoes++;
				printf("ue\n");
				imprimeVetor(vetor2,n);
			}
			i++;
		}	
		if(vetor[i]!=vetor2[i]){
			printf("o i: %d\n", i);
			printf("%d e %d \n", vetor[i], vetor2[i]);
			indice = busca(vetor,vetor2[i],n );
			printf("%d\n", indice);
			imprimeVetor(vetor,n);
			imprimeVetor(vetor2,n);
			for(int k=i; k<indice;k++){
				aux = vetor2[k+1];
				vetor2[k+1]=vetor2[k];
				vetor2[k] = aux;
				inversoes++;
				imprimeVetor(vetor2,n);
			}
		}
		else i++;
		}
	return inversoes;
}
int main(){ 
        int vetor[5] = {1,4,3,2,0};
        int vetor2[5] ={1,4,3,2,0};

        int trocas =contaInversoes(vetor,vetor2,5);
	printf("Trocas: %d \n", trocas);

        return 0;
}

/*
 *int main(){ 
    int tam =0;
    int valor=0;
    scanf("%d",&tam);
    int vetor1[tam];
    int vetor2[tam]
    for(int i =0; i<tam ;i++){
        scanf("%d",&valor);
        vetor1[i]=valor;
    }
    for(int i =0; i<tam ;i++){
        scanf("%d",&valor);
        vetor2[i]=valor;
    }

        int trocas =contaInversoes(vetor1,vetor2,tam);
        printf("%d\n",trocas);

        return 0;
}
*/
