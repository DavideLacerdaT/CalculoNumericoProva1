#include <stdio.h>
#include <math.h>

#define ERRO 0.01

double funcao(double L, double T, double a);
double bisseccao(double L, double a, double S, double x0, double x1);

int main() {
    double S = 32, L = 30, a = 0.1, x0 = 2, x1 = 3;

    double T = bisseccao(L, a, S, x0, x1);

    printf("Portanto, o valor da tensao (T) e: %.6f\n", T);

    return 0;
}

double funcao(double L, double T, double a) {
    return (((2 * T) / a) * sinh((a * L) / (2 * T)));
}

double bisseccao(double L, double a, double S, double x0, double x1) {
    int iteracao = 1;
    double x2;

    printf("i\t x0\t          x1\t         x2\t         f(x)\t\n");
    while ((x1 - x0) / fabs((x0 + x1) / 2.0) > ERRO) {
        x2 = (x0 + x1) / 2.0;

        double fx2 = funcao(L, x2, a);

        printf("%d\t %.6f\t %.6f\t %.6f\t %.6f\t\n", iteracao, x0, x1, x2, fx2);

        if (fabs(fx2 - S) < ERRO) { return x2; }

        if (fx2 < S) { x1 = x2; } 
        else { x0 = x2; }

        iteracao++;
    }
    return x2; 
}