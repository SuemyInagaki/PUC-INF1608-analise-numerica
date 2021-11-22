/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 8 - 23/10/2021
EDO
Nota: 10.0
*/

//gcc main.c ode.c -lm -o ode

#include<stdio.h>
#include<math.h>
#include"ode.h"


static double f (double t, double y){
    return t*y + t*t*t;
}

void calculaErro(double t, double r){
    double y = exp(t*t/2) - t*t - 2;
    double erro = fabs(y - r);
    printf("Valor encontrado: %.16g\n", r);
    printf("Valor esperado:   %.16g\n", y);
    printf("Erro relativo = %.16g\n", erro);
}

int main(){
    double t0, t1, h, y0, tol;
    printf("-------------------------\n");
    printf("Teste 1\n");
    printf("-------------------------\n");
    t0 = 0.0;
    t1 = 2.4;
    h = 0.001;
    y0 = -1;
    double y = RungeKutta(t0, t1, h, y0, f);
    calculaErro(t1, y);

    printf("-------------------------\n");
    printf("Teste 2\n");
    printf("-------------------------\n");
    tol = 1e-12;
    y = RungeKuttaAcoplado(t0, t1, y0, f, tol);
    calculaErro(t1, y);
    return 0;
}