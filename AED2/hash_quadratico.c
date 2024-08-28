#include <stdio.h>

int hash(int k, int i, int m){
        return (( (k%m) + (2*i+(i*i)) )%m);
}

int main(){
        int k,i;
        k=i=0;
        int m=17;
        scanf("%d",&k);
        //scanf("%d",&i);
        
	int h =0;
	for(int a=0; a<m; a++){
		h=hash(k,a,m);
        	printf("Endereco: %d\n",h);
	}
return 0;
}

