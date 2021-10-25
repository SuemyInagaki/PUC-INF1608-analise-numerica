/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 5 - 21/09/2021
Metodo dos Minimos Quadrados
Nota: 10.0
*/

//gcc main.c mmq.c matriz.c sistlinear.c -lm -o mmq

#include "mmq.h"
#include "matriz.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    double auxA[5][3] = {{3, -1, 2}, {4, 1, 0}, {-3, 2, 1}, {1, 1, 5}, {-2, 0, 3}};
    double auxb[5] = {10, 10, -5, 15, 0};
    int m = 5, n = 3;
    double** A = criamat(m, n);
    double* b = criavet(m);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            A[i][j] = auxA[i][j];
        }
        b[i] = auxb[i];
    }
    double* x = mmq(m, n, A, b);
    printf("---------------------------\n");
    printf("Teste 1\n");
    printf("---------------------------\n");
    for(int i = 0; i < n; i++){
        printf("x[%d] = %4f\n", i, x[i]);
    }
    double norma = mmq_norma2(m, n, A, b, x);
    char c = '%';
    printf("Erro associado: %3f %c\n", norma/100, c);
    liberamat(m, A);
    liberavet(b);

    double auxA1[5][4] = {{4, 2, 3, 0}, {-2, 3, -1, 1}, {1, 3, -4, 2}, {1, 0, 1, -1}, {3, 1, 3, -2}};
    double auxb1[5] = {10, 0, 2, 0, 5};
    m = 5;
    n = 4;
    double ** A1 = criamat(m, n);
    double * b1 = criavet(m);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            A1[i][j] = auxA1[i][j];
        }
        b1[i] = auxb1[i];
    }
    double * x1 = mmq(m, n, A1, b1);
    printf("---------------------------\n");
    printf("Teste 2\n");
    printf("---------------------------\n");
    for(int i = 0; i < n; i++){
        printf("x[%d] = %4f\n", i, x1[i]);
    }
    norma = mmq_norma2(m, n, A1, b1, x1);
    printf("Erro associado: %3f %c\n", norma/100, c);
    liberamat(m, A1);
    liberavet(b1);
    printf("---------------------------\n");
    printf("Teste 3\n");
    printf("---------------------------\n");
    double a, bb;
    double auxt[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    double auxc[8] = {8.0, 12.3, 15.5, 16.8, 17.1, 15.8, 15.2, 14.0};
    n = 8;
    
    double* t = criavet(n);
    double* cv = criavet(n);
    for(int i = 0; i < n; i++){
        t[i] = auxt[i];
        cv[i] = auxc[i];
    }
    ajuste(n, t, cv, &a, &bb);
    printf("a = %f\nb = %f\n", a, bb);
    liberavet(t);
    liberavet(cv);
    liberavet(x);
    liberavet(x1);
    return 0;
}