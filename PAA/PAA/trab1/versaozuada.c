#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Visto que o calculo de uma exponencial eh uma sequencia de multiplicacoes, podemos usar um metodo visto em aula que otimiza as multiplicacoes, o metodo de karatsuba, e fazer uma chamada recursiva com os resultados

// Função recursiva pra contar qtd de dígitos
int DigitCount(int v){ 
        if(v < 10)
                return 1;
        else 
                return 1+ DigitCount( (v/10) );
}
// Minha função recursiva pra exp não é tão boa quanto Pow, mas vou usa-la
double expRec(double B, unsigned int n){
        if( n==0)
                return 1;
        return B * expRec(B, n-1);
}


double karatsuba(double x, double y, double dv){ 
        //Divisao do lado esquerdo pro lado direito
        int xe, xr, ye, yr;
        int n1 = DigitCount(x); //Operacao realizada para deixar um tamanho par
        int n2 = DigitCount(y);
        if( (n1 == 1) & (n2 ==1) ) 
            return x*y;
            
        int diff = abs(n1-n2);   //Se os tam são diferentes, preciso saber quem é maior pra adicionar 0.
        if( n1 > n2) {//Se verdade, quer dizer que x tem mais digitos que y
                y = y* expRec(10,diff); //Adiciona dígitos em y
                n2=n2+diff;//aumenta o tamanho que faltava em n2
                if(n2%2 == 1){
                    y = y*10;
                    x = x*10;
                    n1++;
                    n2++;
                    dv=dv+1;
                }
        }
        else if(n1<n2){ 
                x = x* expRec(10,diff); 
                n1 = n1+diff;
                if(n2%2 == 1){
                    y = y*10;
                    x = x*10;
                    n1++;
                    n2++;
                    dv=dv+1;
                }
        }
        if (n1-n2 == 0){  // tem o mesmo tamanho
                xe = (int)(x/(pow(10,n1/2))); //lado esquerdo de x
                xr = (int) (fmod(x, pow(10, n1/2))); // Lado direito de x
                ye = (int)  (y/(pow(10,n2/2))); //Lado esquerdo de y
                yr = (int) (fmod(y,pow(10,n2/2) ) ); // Lado direito de y
}
        unsigned long int a = karatsuba(xe, ye,1); // unsigned long int pra ter mais espaço
        unsigned long int b = karatsuba(xr,yr,1);
        unsigned long int c = karatsuba(xe + xr, ye + yr,1);
        unsigned long int d = c-a-b;
        double result = (a* expRec(10,n1) + d*(expRec(10,n1/2)) +b)/( (pow(10,dv)));
        return result;

}

/*
double expKaratsuba(double B, int n){
        if(n==0)
                return 1;
        if(n==1)
                return B;

 // Desconfio que dê pra otimizar essa etapa quebrando em etapas menores
    double half = expKaratsuba(B, n / 2); // B**n/2 
    double result = karatsuba(half, half); // B**n/2 * B**n/2

    if (n % 2 == 0)
        return result;
    else
        return karatsuba(result, B); //Se o expoente for impar, vai sobrar um pedaço quando fizer B**n/2
                
}
*/
void imprimeDigitoOrdem(double num)
{
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
    double x = 1003;
    double y =430;
    B = karatsuba(x,y,1);
    printf("%lf" ,B );
   // scanf("%lf %u", &B, &N);
    //resp = expKaratsuba(B, N);
    // printf("%.2lf\n", resp);
    // printf("%.5e\n", resp);
    imprimeDigitoOrdem(resp);
    return 0;
}
