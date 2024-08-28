#include <stdio.h>
/*
Passos : 
        - verificar caso de parada
        - passar por todo vetor
        - retornar o maior elemento

*/
void imprime_vetor(int* vetor,int tam){
        for(int i=0; i<tam;i++){
                printf("[%d] : %d\n ",i,vetor[i]);  
        }
}

int* maior_elemento(int* vetor,int tam,int i){
       // if(i==0){
         //       sum[0]= vetor[i];
        //}
        if (vetor[i]==vetor[tam]){
                printf("\n Maior valor: %d\n",vetor[i]);
                return vetor;
        }
        else{ 
                if (vetor[i] >= vetor[i+1]){
                        vetor[i+1]=vetor[i];
                }
                        maior_elemento(vetor,tam,i+1);

        }
}


int main() {
        int vetor[8] = {2,4,6,1,500,2,-3,7};
        //int sum[1];
        //printf("%d",sum[0]);
        maior_elemento(vetor,8,0);
        imprime_vetor(vetor,8);

return 0;
}

