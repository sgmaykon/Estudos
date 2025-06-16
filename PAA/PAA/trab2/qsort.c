#include <stdio.h>
#include <stdlib.h>
#define TAM 8
int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int main(){
	int vetor[TAM]={14,76,68,9,11,81,95,25};
	qsort(vetor,TAM,sizeof(int),compare);
	for(int i=0; i<TAM;i++)
			printf("%d, ",vetor[i]);

	return 0;

}
