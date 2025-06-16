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
	for(int i =0; i<n; i++){
		printf("%lf, ", v[0][i]);
	}
	printf("\n");
	for(int i =0; i<n; i++){
		printf("%lf, ", v[1][i]);
	}
	printf("\n");
	for(int i =0; i<s;i++){
		if(v[i][k+1] > l)
		       outliers++;
	}	
	return outliers;		
			
}



int main(){
	double vetor[2][5] ={ {0,1,1.5,3,2} ,{1,0,2,5,1.5} };
	int resp = outliers(5,vetor, 1, 1.3, 2);
	printf("%d",resp);
return 0;
}
