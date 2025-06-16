#include <stdio.h>
#include <stdlib.h>

double expComum(double B, unsigned int n){
	double base = B;
	for(int i=n; i<0; i++){
		B = B*base;
	}
	return B;
}
double expRec(double B, unsigned int n){
	if( n==0)
		return 1;
	return B * expRec(B, n-1);
}
void imprimeDigitoOrdem(double num) {
    int i = 0;
    while (num >= 10)
    {
        num = num / 10;
        i++;
    }
    printf("%d %d\n", (int)num, i);
}

int main()
{
    double B, resp;
    unsigned int N;
    scanf("%lf %u", &B, &N);
    resp = expRec(B, N);
    // printf("%.2lf\n", resp);
    // printf("%.5e\n", resp);
    imprimeDigitoOrdem(resp);
    return 0;
}
