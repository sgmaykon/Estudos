/*Maykon dos Santos Gonçalves
RA: 821653 
Curso: Engenharia de Computação
*/


#include <stdio.h>
/* Vou ordernar os preços, e percorrer o vetor de tras pra frente
    dai, pegar todo terceiro elemento e somar o valor.
*/

void swap(long long int* a, long long int* b){
    long long int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(long long int vetor[], int e, int d) {
    
    long long int p = vetor[e];
    int i =e;
    int j = d;
    
    while(i < j){
        //Só inverter a comparação
        while (vetor[i] >=p && i <= d-1){
            i++;
        }
        //Só inverter a comparação
        while (vetor[j] < p && j >=e+1){
            j--;
        }
        if (i < j){
            swap(&vetor[i],&vetor[j]);
        }
    }
    swap (&vetor[e],&vetor[j]);
    return j;
}


void quicksort(long long int vetor[], int e, int d){
    if (e<d){
        long long int pi = partition(vetor,e,d);
        quicksort(vetor,e,pi-1);
        quicksort(vetor,pi+1,d);
    }
}

long long int descontoTotal(long long int vetor[],long long int tam){
    long long int desconto =0;
    for(long long int i=2; i<tam; i+=3){
        desconto += vetor[i];
        if(i+3 == tam)
            desconto+=vetor[i+3];
    }
    return desconto;

}

void imprime(long long int vetor[],long long int tam){
    for(long long int i=0; i< tam; i++){
        printf(" %Ld,",vetor[i]);}
    printf("\n");
}
int main()
{
    long long int tam =0;
    scanf("%Ld",&tam);
   long long int vetor[tam];
    for (long long int i = 0; i < tam; i++)
        scanf("%Ld", &vetor[i]);
    quicksort(vetor,0,tam-1);
  
   
    long long int desconto =descontoTotal(vetor,tam-1);
    printf("%Ld\n",desconto);
   
    return 0;
}

