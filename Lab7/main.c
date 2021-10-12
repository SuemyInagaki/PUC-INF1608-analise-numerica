/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 7 - 11/10/2021
Metodos de Integração Adaptativa
*/

//gcc main.c trapezio.c -lm -o trapezio
#include<stdio.h>
#include<math.h>
#include"trapezio.h"

#define PI 3.1415926535897932384

static double f (double x){
    return x/(sqrt(x*x + 9));
}

static double g (double x){
    return 2*exp(-x*x)/sqrt(PI);
}

static double h (double x){
    return log(cos(x) + sin(x));
}


int main(){
    double tol = 1e-5;
    double a = 0.0;
    double b = 1.0;
    double r = adaptiva(a, b, f, tol);
    //0.1622776601683793
    printf("-------------------------\n");
    printf("Teste 1 - Integral 1\n");
    printf("-------------------------\n");
    printf("tol = %.16g\n", tol);
    printf("res = %.16g\n", r);
    tol = 1e-10;
    r = adaptiva(a, b, f, tol);
    printf("-------------------------\n");
    printf("Teste 2 - Integral 1\n");
    printf("-------------------------\n");
    printf("tol = %.16g\n", tol);
    printf("res = %.16g\n", r);
    tol = 1e-2;
    r = adaptiva(a, b, f, tol);
    printf("-------------------------\n");
    printf("Teste 3 - Integral 1\n");
    printf("-------------------------\n");
    printf("tol = %.16g\n", tol);
    printf("res = %.16g\n", r);

    a = 0.0;
    b = 3.0;
    r = adaptiva(a, b, g, tol);
    printf("-------------------------\n");
    printf("Teste 1 - Integral 2\n");
    printf("-------------------------\n");
    printf("tol = %.16g\n", tol);
    printf("res = %.16g\n", r);
    tol = 1e-10;
    r = adaptiva(a, b, g, tol);
    printf("-------------------------\n");
    printf("Teste 2 - Integral 2\n");
    printf("-------------------------\n");
    printf("tol = %.16g\n", tol);
    printf("res = %.16g\n", r);
    tol = 1e-2;
    r = adaptiva(a, b, g, tol);
    printf("-------------------------\n");
    printf("Teste 3 - Integral 2\n");
    printf("-------------------------\n");
    printf("tol = %.16g\n", tol);
    printf("res = %.16g\n", r);

    a = 0.0;
    b = PI/2;
    r = adaptiva(a, b, h, tol);
    printf("-------------------------\n");
    printf("Teste 1 - Integral 3\n");
    printf("-------------------------\n");
    printf("tol = %.16g\n", tol);
    printf("res = %.16g\n", r);
    tol = 1e-10;
    r = adaptiva(a, b, h, tol);
    printf("-------------------------\n");
    printf("Teste 2 - Integral 3\n");
    printf("-------------------------\n");
    printf("tol = %.16g\n", tol);
    printf("res = %.16g\n", r);
    tol = 1e-2;
    r = adaptiva(a, b, h, tol);
    printf("-------------------------\n");
    printf("Teste 3 - Integral 3\n");
    printf("-------------------------\n");
    printf("tol = %.16g\n", tol);
    printf("res = %.16g\n", r);

    printf("\n\n-------------------------\n");
    printf("Teste da função Probabilidade\n");
    printf("-------------------------\n");
    double sigma = 1.0;
    r = probabilidade(sigma);
    printf("sigma = %f\n", sigma);
    printf("res = %.16g\n", r);
    sigma = 2.0;
    r = probabilidade(sigma);
    printf("sigma = %f\n", sigma);
    printf("res = %.16g\n", r);
    return 0;
}