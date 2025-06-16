/*Maykon dos Santos Goncalves
RA: 812653
Curso: Engenharia de Computacao

*/
#include <stdio.h>

// Função para contar e mesclar durante o Merge Sort
int merge_genomico(unsigned long int vetor[], unsigned long int temp[],unsigned long int left, unsigned long  int mid, unsigned long int right) {
    unsigned long int i = left;    
    unsigned long int j = mid + 1; 
    unsigned long int k = left;    
    unsigned long int inversions = 0;

    while (i <= mid && j <= right) {
        if (vetor[i] <= vetor[j]) {
            temp[k++] = vetor[i++];
        } else {
            temp[k++] = vetor[j++];
            inversions += (mid + 1 - i); // Contar as inversões
        }
    }

    // Copiar os elementos restantes do subvetor esquerdo
    while (i <= mid) {
        temp[k++] = vetor[i++];
    }

    // Copiar os elementos restantes do subveto direito
    while (j <= right) {
        temp[k++] = vetor[j++];
    }

    // Copiar de volta para o vetor original
    for (i = left; i <= right; i++) {
        vetor[i] = temp[i];
    }

    return inversions;
}

int mergeSort_Inversions(unsigned long int vetor[], unsigned long int temp[],unsigned long  int left,unsigned long int right) {
    unsigned long int mid, inversions = 0;
    if (left < right) {
        mid = (left + right) / 2;

        inversions += mergeSort_Inversions(vetor, temp, left, mid);
        inversions += mergeSort_Inversions(vetor, temp, mid + 1, right);

        inversions += merge_genomico(vetor, temp, left, mid, right);
    }
    return inversions;
}

void mapG(unsigned long int *vetor1, unsigned long int *vetor2, int tam) {
        unsigned long int vetor_map[tam];
        unsigned long int vetor_g2parag1[tam];
        unsigned long int temp[tam]; //Usado no mergeSort
    for (int i = 0; i < tam; i++) {
        vetor_map[vetor1[i]] = i;
    }

    for (int i = 0; i < tam; i++) {
        vetor_g2parag1[i] = vetor_map[vetor2[i]];
    }

    // Contar inversões usando Merge Sort
   unsigned long int inversions = mergeSort_Inversions(vetor_g2parag1, temp, 0, tam- 1);

    printf("%ld\n", inversions);

}

int main() {
        int tam;
        scanf("%d", &tam);

        unsigned long int genoma1[tam];
        unsigned long int genoma2[tam];

        for(int i =0; i<tam; i++)
                scanf("%d",&genoma1[i]);
        for(int i =0; i<tam; i++)
                scanf("%d", &genoma2[i]);

        mapG(genoma1,genoma2, tam);

        return 0;
}

