/*
Maykon dos Santos Gonçalves
RA: 812653
Curso: Engenharia de Computação
*/
#include <stdio.h>

int busca(int *vetor,int elemento,int tam){
        for(int i=0; i< tam;i++){
                if (vetor[i] ==elemento)
                        return i;
                }
        return -1;
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
                        }
                        i++;
                }
                if(vetor[i]!=vetor2[i]){
                        indice = busca(vetor,vetor2[i],n );
                        for(int k=i; k<indice;k++){
                                aux = vetor2[k+1];
                                vetor2[k+1]=vetor2[k];
                                vetor2[k] = aux;
                                inversoes++;
                        }
                }
                else i++;
                }
        return inversoes;
}
int main(){ 
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

