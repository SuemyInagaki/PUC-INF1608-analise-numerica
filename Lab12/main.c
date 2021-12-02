/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 12 - 22/11/2021
Otimização
Nota: 10.0
*/

//gcc main.c otimizacao.c -lm -o otimizacao

#include"otimizacao.h"
#include<math.h>
#include<stdio.h>
#include<stdlib.h>


static double f (double x){
    return x*x + sin(x);
}

static double g (double x){
    return x*(x*(x*(x*x*x - 11) + 17) - 7) + 1;
}
int main(){
    double a, b, tol, xmin;
    int q;
    a = -1.5;
    b = 0;
    tol = 1e-7;
    printf("-------------------------------\n");
    printf("Teste 1\n");
    printf("-------------------------------\n");
    printf("Funcao f\n");
    q = SecaoAurea(a, b, f, tol, &xmin);
    printf("Num de iteracoes: %d\n", q);
    printf("Xmin = %f\n", xmin);
    printf("Funcao g\n");
    a = 0.2;
    b = 1.0;
    q = SecaoAurea(a, b, g, tol, &xmin);
    printf("Num de iteracoes: %d\n", q);
    printf("Xmin = %f\n", xmin);

    printf("-------------------------------\n");
    printf("Teste 2\n");
    printf("-------------------------------\n");
    printf("Funcao f\n");
    double c = 0;
    a = -0.8; b = -0.4;
    q = MIPS(a, b, c, f, tol, &xmin);
    printf("Num de iteracoes: %d\n", q);
    printf("Xmin = %f\n", xmin);
    printf("Funcao g\n");
    a = 0;
    b = 1.0;
    c = 1.5;
    q = MIPS(a, b, c, g, tol, &xmin);
    printf("Num de iteracoes: %d\n", q);
    printf("Xmin = %f\n", xmin);
    return 0;
}