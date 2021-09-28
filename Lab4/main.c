/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 4 - 14/09/2021
Interpolação de Polinomios
Nota: 10.0
*/

//gcc main.c interp.c -o interp

#include "interp.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415926535897932384

static double f (double x){
    return x*x*x*x*x*x*x*x;
}

static double g (double x){
    return 1.0/(0.5 * sqrt(2*PI)) * exp(-(0.5)*((x - 0.0)/0.5)*(x - 0.0)/0.5);
}

void testa(int n, double a, double b, double (*f) (double x), double* teste, int tamTeste);
int main(){

    
    double a, b;
    a = -2.0;
    b = 2.0;
    int n = 8;
    double teste[8] = {-2.0, -1.6, -1.2, 0, 0.4, 0.8, 1.2, 2.0};
    printf("Teste 1\n");
    printf("n = 8\n");
    testa(n, a, b, g, teste, 8);
    printf("\n\n");
    printf("Teste 2\n");
    printf("n = 20\n");
    n = 20;
    testa(n, a, b, g, teste, 8);
    printf("\n\n");
    printf("Teste 3\n");
    printf("n = 100\n");
    n = 100;
    testa(n, a, b, g, teste, 8);
    printf("\n\n");
    printf("Teste 3\n");
    printf("n = 200\n");
    n = 200;
    testa(n, a, b, g, teste, 8);

    return 0;
}

void testa(int n, double a, double b, double (*f) (double x), double* teste, int tamTeste){
    double* xi = (double*)malloc(n*sizeof(double));
    double* yi = (double*)malloc(n*sizeof(double));;
    double x, y, yEsperado, erroR = 0.0, erroC = 0.0;
    printf("-------------------------------\n");
    printf("Espacamento regular\n");
    printf("-------------------------------\n");
    regular(n, a, b, f, xi, yi);
    for(int i = 0; i < tamTeste; i++){
        y = lagrange(n, xi, yi, teste[i]);
        yEsperado = f(teste[i]);
        printf("  f(%.2f) = %.16g\n", teste[i], yEsperado);
        printf("lag(%.2f) = %.16g\n", teste[i], y);
        if(erroR < (fabs(y - yEsperado))){
            erroR = fabs(y - yEsperado);
        }
    }
    printf("\n-------------------------------\n");
    printf("Espacamento Chebyshev\n");
    printf("-------------------------------\n");
    chebyshev(n, a, b, f, xi, yi);
    for(int i = 0; i < tamTeste; i++){
        y = lagrange(n, xi, yi, teste[i]);
        yEsperado = f(teste[i]);
        printf("  f(%.2f) = %.16g\n", teste[i], yEsperado);
        printf("lag(%.2f) = %.16g\n", teste[i], y);
        if(erroC < (fabs(y - yEsperado))){
            erroC = fabs(y - yEsperado);
        }
    }
    // char c = '%';
    printf("\n\n");
    printf("Erro Regular = %.16g\n", erroR);
    printf("Erro Chebysh = %.16g\n", erroC);
    free(xi);
    free(yi);
}