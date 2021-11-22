/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 10 - 09/11/2021
Métodos Iterativos para Sistemas Lineares
*/
#include <math.h>
#include "matriz.h"
#include <stdio.h>
int diagonal_dominante (int n, double** A){
    double d, soma;
    for(int i = 0; i < n; i++){
        d = fabs(A[i][i]);
        soma = 0.0;
        for(int j = 0; j < n; j++){
            if(i != j){
                soma+= fabs(A[i][j]);
            }
        }
        if (d <= soma){
            return 0;
        }
    }
    return 1;
}

int gauss_seidel (int n, double** A, double* b, double* x, double tol){
    
    double d;
    int r = diagonal_dominante(n, A);
    if(r == 0){
        return 0;
    }
    double r2 = 1.0;
    int count = 0;
    double* residuo = criavet(n);
    double* produto = criavet(n);
    while(r2 > tol){
        for(int i = 0; i < n; i++){
            d = A[i][i];
            if(i != j){
                multmv(n, n, A, x, produto);
            }
            x[i] = b[i] - produto[i];
            x[i] = x[i]/d;
        }
        // multmv(n, n, A, x, produto);
        for(int k = 0; k < n; k++){
            residuo[k] = b[k] - x[k];
            // printf("r=%.3f\n", residuo[k]);
        }
        r2 = norma2(n, residuo);
        count++;
        // printf("%d\n", count);
    }
    // printf("%f\n", r2);
    return count;
}