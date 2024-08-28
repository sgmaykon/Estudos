int particaoUltimoElemento(double *vetor,int primeiro,int ultimo){
        double x = vetor[ultimo]; //Definindo o ultimo elemento como pivo
        int i = primeiro-1;
        double aux=0;
        for (int j=primeiro; j<= ultimo-1;j++){ //Para percorrer o vetor
                if (vetor[j] <= x){ 
                        i=i+1; //aumenta o indice do lado esquerdo
                        aux=vetor[i]; vetor[i]=vetor[j]; vetor[j]=aux;
                }   
        }   
        aux = vetor[i + 1]; 
        vetor[i + 1] = vetor[ultimo];
        vetor[ultimo] = aux;
        return i+1;
}

void Quicksort(double *vetor,double  primeiro, double ultimo){
        if (primeiro < ultimo){
                double q = particaoUltimoElemento(vetor,primeiro,ultimo);
                Quicksort(vetor,primeiro,q-1); //Ordena o lado direito
                Quicksort(vetor,q+1,ultimo);
        }   
}
    
