#include <stdio.h>


//n = Pessoas, k = Passos
//Deve avan�ar de k em k
//Sabemos que a pessoa na posicao = k, sempre morre. Ent�o  o sobrevivente nunca vai estar em k. Acontece que isso vale pra todo ciclo, k-1 sempre sobrevive.
//Tamb�m sei, por conta do primeiro algoritmo que desenvolvi, que é possivel limitar o indice da fun�ao utilizando modulo, dessa forma, k nunca vai sair
//de dentro do escopo de n
//Para resolver o problema, Será chamada uma fun��o recusiva que tem como paramentro (n-1,k) para avan�ar pelas pessoas.
// A fun��o sempre retornaráo sobrevivente, ent�o vou modelar apartir disso, sabendo que o sobrevivente é um n�mero inteiro
// Entao pra cada itera��o, quero reduzir n-1, isso me da a pessoa atual, e quero 
//Modelando o problema para n= 3, k=1, temos:
//
//Pessoa 1 mata pessoa 2  ((func(n-1,k) + k-1)%n)   = 3-1 + 1-1 = 2. O 2 morreu... Ta fora por 1. Isso porque tamb�m s�o consideradas pessoas na posicao 0, ent�o é necessario soma +1 para te								r o resultado correto 
//Pessoa 3 mata pessoa 2  (n+k) 			 O modulo, como eu ja disse, é ra limitar o avan�o, ja que n+k sempre émaior que n.  para avan�ar pra proxima pessoa
//Pessoa 3 sobrevive
//
//
//

int sobrevive(int n, int k){
    if(n==1) return 1;
    return (((sobrevive(n-1, k) + k-1)%n)+1);   
	

}
int main(){


return 0;

}
