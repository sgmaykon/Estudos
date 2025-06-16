#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {

    if (*(double*)a > *(double*)b) return 1;
    else if (*(double*)a < *(double*)b) return -1;
    else return 0;
}

double outliers(int n, int s, int k, double v[s][n]) {
    double soma = 0.0;

    for (int i = 0; i < s; i++) {
        // Ordena as distâncias para o i-ésimo objeto
        qsort(v[i], n, sizeof(double), compare);
        // A distância do k-ésimo vizinho mais próximo é v[i][k+1] (já que v[i][0] é a distância para si mesmo)
        soma += v[i][k + 1];
	printf("vetor: %lf\n", v[i][k+1]);
    }

    // Calcula a média
    printf("soma: %lf\n",soma);
    return soma / s;
}


int main(){
        int n,k,s;
        double resposta =0;
        scanf("%d",&n);
        scanf("%d",&s);
        scanf("%d",&k);
        double vetor[s][n];
        for(int i=0; i<s;i++){
            for( int j=0; j<n;j++){
                scanf("%lf",&resposta);
                vetor[i][j] = resposta;
            }
	}
        resposta = outliers(n,s,k,vetor);
        printf("%.2lf\n",resposta);
return 0;
}
