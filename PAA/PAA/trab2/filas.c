/*Maykon dos Santos Gonçalves
RA: 821653
Curso: Engenharia de Computação
*/
#include <stdio.h>
int main()
{
    int tam;
    int valor;
    scanf("%d",&tam);
    int vetor[1000001] = {0};
    int check[1000001] = {0};
    int count =0;
    
   
    for(int i=0; i< tam;i++){
        scanf("%d",&valor);
        if (check[valor] == 0){ //O valor ainda não apareceu
            vetor[i]=valor;//Adiciona o novo valor na fila
            if (i ==0)
                check[valor]=-1;
            else
                check[valor] = i;//Adiciona a lista de verificações aquele valor que já apareceu
            count++; //Aumenta o tamanho real da fila
        }
        
        else{
            int indice = check[valor];
            if (indice ==-1)
                vetor[0]=0;
            else
                vetor[indice] =0;
            vetor[i] = valor;
            check[valor] =i;
            count++;
        }
    }

   for (int i = 0; i < count; i++) {
    if (vetor[i] != 0) { // Imprime apenas valores válidos
        if (i == count - 1) { // Último elemento válido
            printf("%d\n", vetor[i]);
        } else {
            printf("%d ", vetor[i]); // Com espaço
        }
    }
}

    
   
    return 0;
}
