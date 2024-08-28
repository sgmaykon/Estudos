/* Algoritmo Recursivo que conta a quantidade de caracteres em um string */

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
int string_count(char* cadeia,int i,int counter){
	
	if(cadeia[i]=='\0'){
		printf("TAMANHO: %d",counter);
		return counter;
		}
		else{
			string_count(cadeia,i+1,counter+1);	
		}
	return counter;
	
}
int main() {
	char cadeia[]="01234569";
	string_count(cadeia,0,0);
return 0;

}
