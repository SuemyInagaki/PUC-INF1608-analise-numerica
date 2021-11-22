/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 10 - 09/11/2021
Métodos Iterativos para Sistemas Lineares
*/
//gcc main.c metiter.c matriz.c -lm -o metiter
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "matriz.h"
#include "metiter.h"

int main(){
    int n = 2;
    printf("-------------------------\n");
    printf("Teste 1\n");
    printf("-------------------------\n");
    double** A = criamat(n, n);
    A[0][0] = 3.0;
    A[0][1] = 1.0;
    A[1][0] = 1.0;
    A[1][1] = 2.0;
    double* b = criavet(n);
    b[0] = 5;
    b[1] = 5;
    int r = diagonal_dominante(n, A);
    if(r == 1){
        printf("Ah matriz eh diagonal dominante\n");
    }
    else{
        printf("Ah matriz nao eh diagonal dominante\n");
    }
    double tol = 1e-7;
    double* x = criavet(n);
    x[0] = 0.0;
    x[1] = 0.0;
    r = gauss_seidel(n, A, b, x, tol);
    printf("Solução aproximada\n");
    printf("No de iteracoes = %d\n", r);
    for(int i = 0; i < n; i++){
        printf("%.3f\n", x[i]);
    }
    return 0;
}