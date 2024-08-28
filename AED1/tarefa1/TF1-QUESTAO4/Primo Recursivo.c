#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n,int i) {
	if(n==0 && n==1)
		return 0;
	else{
		if(n!=i){
			if (n%i==0)
				return 0;
			else isPrime(n,i+1);
		}
	return 1;
	}
}
int main(){
	printf("Primo?: %s\n",isPrime(2,2) ? "Sim" : "NÃo"); 	//Sim 
	printf("Primo?: %s\n",isPrime(53,2) ? "Sim" : "NÃo");   //Sim
	printf("Primo?: %s\n",isPrime(48,2) ? "Sim" : "NÃo");   //Nao
	printf("Primo?: %s\n",isPrime(18,2) ? "Sim" : "NÃo");   //Nao
	printf("Primo?: %s\n",isPrime(3,2) ? "Sim" : "NÃo");    //Sim


return 0;
}
