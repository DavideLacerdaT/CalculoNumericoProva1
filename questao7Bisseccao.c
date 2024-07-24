#include <stdio.h>
#include <math.h>

#define ERRO 0.0001 

double funcao(double F, double i, int n);
double bisseccao(double F, double P, int n, double x0, double x1);

int main() {
    double F = 2499, P = 249, x0 = 0.0, x1 = 1.0;

    int n = 12;

    double i = bisseccao(F, P, n, x0, x1);

    printf("Portanto, o valor da taxa de juros (i) e aproximadamente: %.6f\n", i);

    return 0;
}

double funcao(double F, double i, int n) {
    return (F * i) / (1 - pow(1 + i, -n));
}

double bisseccao(double F, double P, int n, double x0, double x1) {
    int iteracao = 1;
    double x2;

    printf("i\t x0\t          x1\t         x2\t         f(x)\t\n");

    while ((x1 - x0) >= ERRO) {
        x2 = (x0 + x1) / 2.0;
        
        double fx2 = funcao(F, x2, n);

        printf("%d\t %.6f\t %.6f\t %.6f\t %.6f\t\n", iteracao, x0, x1, x2, fx2);

        if (fabs(fx2 - P) < ERRO) { return x2; }

        if (fx2 > P) { x1 = x2; } 
        else { x0 = x2; }

        iteracao++;
    }
    return x2; 
}