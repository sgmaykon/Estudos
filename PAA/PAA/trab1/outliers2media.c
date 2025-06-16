#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {

    if (*(double*)a > *(double*)b) return 1;
    else if (*(double*)a < *(double*)b) return -1;
    else return 0;
}


double outliers(int n, double v[][n], int k, int s){
        double soma =0;
	int qtdsoma= 0;
        for( int i =0; i<s;i++){
                qsort(v[i], n, sizeof(double),compare);
        }
        for(int i =0; i<n; i++){
                printf("%lf, ", v[0][i]);
        }
        printf("\n");
        for(int i =0; i<n; i++){
                printf("%lf, ", v[1][i]);
        }
        printf("\n");
        for(int i =0; i<s;i++){
		for(int j = k+1; j < n; j++){
			soma = soma + v[i][j]; 
			qtdsoma++;
		}	
	}
	printf("DEBUG: %d\n", qtdsoma);
        printf("DEBUG; %lf\n", soma);
        return soma/(2*n);
}



int main(){
        double vetor[2][5] ={ {0,1,1.5,3,2} ,{1,0,2,5,1.5} };
        double resp = outliers(5,vetor, 1, 2);
	
	printf("%lf",resp);
return 0;
}

