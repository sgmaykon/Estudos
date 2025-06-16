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


double karatsuba(double x, double y) {
    int n1 = DigitCount(x);
    int n2 = DigitCount(y);
    int scale = 0;

    if (n1 == 1 && n2 == 1)
        return x * y;

    // Ajustar tamanhos para serem iguais
    if (n1 != n2) {
        int diff = abs(n1 - n2);
        if (n1 > n2) {
            y *= pow(10, diff);
            scale += diff;
        } else {
            x *= pow(10, diff);
            scale += diff;
        }
    }

    // Garantir número par de dígitos
    if (n1 % 2 != 0) {
        x *= 10;
        y *= 10;
        scale++;
    }

    int m = n1 / 2;
    double xe = floor(x / pow(10, m));   // Lado esquerdo de x
    double xr = fmod(x, pow(10, m));    // Lado direito de x
    double ye = floor(y / pow(10, m));  // Lado esquerdo de y
    double yr = fmod(y, pow(10, m));    // Lado direito de y

    // Recursão
    double a = karatsuba(xe, ye);
    double b = karatsuba(xr, yr);
    double c = karatsuba(xe + xr, ye + yr);
    double d = c - a - b;

    // Combinar resultados
    double result = a * pow(10, 2 * m) + d * pow(10, m) + b;
    result /= pow(10, scale);  // Ajustar escala se necessário

    return result;
}


double expKaratsuba(double B, int n){
        if(n==0)
                return 1;
        if(n==1)
                return B;
                
    if (fmod(B, 1) != 0.0) {
        double preciseHalf = pow(B, n / 2.0); 
        return preciseHalf * preciseHalf;
    }
    
 // Desconfio que dê pra otimizar essa etapa quebrando em etapas menores
    double half = expKaratsuba(B, n / 2); // B**n/2 
    double result = karatsuba(half, half); // B**n/2 * B**n/2

    if (n % 2 == 0)
        return result;
    else
        return karatsuba(result, B); //Se o expoente for impar, vai sobrar um pedaço quando fizer B**n/2
                
}

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
    scanf("%lf %u", &B, &N);
    resp = expKaratsuba(B, N);
    // printf("%.2lf\n", resp);
    // printf("%.5e\n", resp);
    imprimeDigitoOrdem(resp);
    return 0;
}
