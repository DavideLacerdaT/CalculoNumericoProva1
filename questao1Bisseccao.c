#include <stdio.h>
#include <math.h>

#define ERRO 0.008 

double funcao(double u, double t, double m0, double g, double c);
double bisseccao(double u, double m0, double g, double c, double v, double x0, double x1);

int main() {
    double u = 200, m0 = 1600, g = 9.8, c = 27, v = 100, x0 = 6, x1 = 8;

    double t = bisseccao(u, m0, g, c, v, x0, x1);

    printf("Portanto, o valor do tempo (t) e: %.6f\n", t);

    return 0;
}

double funcao(double u, double t, double m0, double g, double c) {
    return u * log(m0 / (m0 - (c * t))) + g * t;
}

double bisseccao(double u, double m0, double g, double c, double v, double x0, double x1) {
    int iteracao = 1;
    double x2, erroRelativo;
    printf("i\t x0\t          x1\t         x2\t         f(x)\t         Erro Relativo\n");
    while ((x1 - x0) / fabs((x0 + x1) / 2.0) > ERRO) {
        x2 = (x0 + x1) / 2.0;
        double fx2 = funcao(u, x2, m0, g, c);

        erroRelativo = fabs(x1 - x0) / fabs((x0 + x1) / 2.0);

        printf("%d\t %.6f\t %.6f\t %.6f\t %.6f\t %.6f\t\n", iteracao, x0, x1, x2, fx2, erroRelativo);

        if (fabs(fx2 - v) < ERRO) { return x2; }

        if (fx2 > v) { x1 = x2; } 
        else { x0 = x2; }

        iteracao++;
    }
    return x2; 
}