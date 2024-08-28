#include <stdio.h>

int maior_valor(int vetor[],int tam){
        int maior;
        maior=vetor[0];
        for(int i =0; i<tam;i++){
                if(vetor[i]>maior)
                        maior=vetor[i];
        }
        return maior;
}
void zera_vetor(int *vetor, int tam){
        for(int i=0;i<tam;i++){
                vetor[i]=0;
        }
}

void Counting(int *vetor, int tam){
        int max = maior_valor(vetor, tam) +1;
        int vetor2[max];
        int vetorC[max];
        int vetorS[tam];
        zera_vetor(vetor2,max);
        zera_vetor(vetorC,max);
        zera_vetor(vetorS,tam);

        for(int i = 0;i<tam; i++){
                vetor2[vetor[i]] = vetor2[vetor[i]]+1; //Acessa o elemento dentro do vetor, e atribui pro mesmo indice a quantidade de aparicoes
        }

        for(int i=1;i<max;i++){
                vetorC[i] = (vetorC[i-1]+vetor2[i]); //Cria o vetor C, com contagens
        }

        for(int i=0;i<tam;i++){
                vetorS[vetorC[vetor[i]]-1] =vetor[i]; //Adiciona no vetor S o valor de L no indice certo
                vetorC[vetor[i]]=vetorC[vetor[i]]-1; // Remove um do valor do indice, pra que seja alocado a esquerda do anterior
        }

        // Instrucoes necessarias abaixo para usar o vetor S na main.;
        for(int i=0;i<tam;i++){
                vetor[i]=vetorS[i];
        }
}

