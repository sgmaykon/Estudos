/*
Maykon dos Santos Gonçalves
RA: 821653
Curso: Engenharia de Computação

*/
// #define MAX 100

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {

    if (*(double*)a > *(double*)b) return 1;
    else if (*(double*)a < *(double*)b) return -1;
    else return 0;
}


int outliers(int n, double v[][n], int k, double l, int s){
        int outliers =0;
        for( int i =0; i<s;i++){
                qsort(v[i], n, sizeof(double),compare);
        }
        for(int i =0; i<s;i++){
                if(v[i][k+1] > l)
                       outliers++;
        }
        return outliers;

}


int main(int argc, char *argv[])
{
    // char file_name[MAX];
    // FILE *entrada;
    int n,s,k;
    double l;


    // lendo o tamanho de um vetor e os elementos do mesmo
    scanf("%d", &n);
    scanf("%d", &s);
    scanf("%d", &k);
    scanf("%lf",&l);
    double vetor[s][n];
    for(int i =0; i<s;i++){
	    for(int j=0; j<n;j++){
	    scanf("%lf", &vetor[i][j]);
	    }
    }
    // crie uma funcao que resolva o problema
    int resp =outliers(n,vetor,k,l,s);
    printf("%d\n",resp);

    // fclose(entrada);
    return 0;
}

