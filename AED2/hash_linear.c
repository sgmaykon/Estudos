#include <stdio.h>

int hash(int k, int i, int m){
	return (((k%m)+i)%m);
}

int main(){
	int k,i;
	k=i=0;
	int m=17;
	scanf("%d",&k);
	scanf("%d",&i);
	int h =hash(k,i,m);
	printf("Endereco: %d\n",h);	
return 0;
}
