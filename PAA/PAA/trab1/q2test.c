#include <stdio.h>
int contaInversoes(int v[], int u[], int n) {
    int trocas = 0;
    int aux = 0;

    for (int i = 0; i < n; i++) {
        if (v[0] == u[n-1]) { // Se o primeiro elemento de v for igual ao último de u
            // Inicia trocas de u[n-1] até u[0]
            for (int j = n-1; j > 0; j--) {
                aux = u[j-1];
                u[j-1] = u[j];
                u[j] = aux;
                trocas++;
            }
        } else {
            // Caso padrão: Comparar o valor no índice atual de u com v
            if (v[i] != u[i]) {
                // Realizar trocas para ajustar a posição do elemento de u
                for (int j = i; j < n-1; j++) {
                    aux = u[j];
                    u[j] = u[j+1];
                    u[j+1] = aux;
                    trocas++;
                }
            }
        }
    }

    return trocas;
}

int main(){ 
	int vetor[5] = {4,3,2,1,0};
	int vetor2[5] ={0,1,2,3,4};

	int trocas =contaInversoes(vetor,vetor2,5);
	printf("Trocas: %d \n", trocas);

	return 0;
}
