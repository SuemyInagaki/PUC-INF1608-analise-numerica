/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 3 - 02/09/2021
Sistema Linear
Nota: 10.0
*/

//gcc main.c sistlinear.c matriz.c -o sistlinear
#include <stdio.h>
#include "sistlinear.h"
#include "matriz.h"

void exibeVetor(int n, double* v){
    printf("[");
    for(int i = 0; i < n - 1; i++){
        printf("%.3lf ", v[i]);
    }
    printf("%.3lf]\n", v[n-1]);
}

void exibeMatriz(int n, double** M){
    for(int i = 0; i < n; i++){
        exibeVetor(n, M[i]);
    }
}

int main(){
    int n = 3;
    double Aaux[3][3] = {{1, 2, -1}, {2, 1, -2}, {-3, 1, 1}};
    double baux[3] =  {3, 3, -6};
    double** A = criamat(n, n);
    double* b = criavet(n);
    double* x = criavet(n);
    for(int i = 0; i < n; i++){
        b[i] = baux[i];
        for(int j = 0; j < n; j++){
            A[i][j] = Aaux[i][j];
        }
    }
    printf("-----------------------------------------\n");
    printf("Teste 1\n");
    printf("-----------------------------------------\n");
    printf("\nMatriz:\n");
    exibeMatriz(n, A);
    printf("\nVetor b:\n");
    exibeVetor(n, b);
    gauss(n, A, b, x);
    printf("\nSolucao: \n");
    exibeVetor(n, x);
    printf("\n");
    liberamat(n, A);
    liberavet(b);
    liberavet(x);
    printf("\n-----------------------------------------\n");
    printf("Teste 2\n");
    printf("-----------------------------------------\n");
    n = 6;
    double Aaux2[6][6] = {{3, -1.0, 0, 0, 0, 0.5}, 
    {-1.0, 3, -1.0, 0, 0.5, 0},
    {0, -1.0, 3, -1.0, 0, 0},
    {0, 0, -1.0, 3, -1.0, 0},
    {0, 0.5, 0, -1.0, 3, -1.0},
    {0.5, 0, 0, 0, -1.0, 3}};
    double baux2[6] = {2.5, 1.5, 1.0, 1.0, 1.5, 2.5};
    A = criamat(n, n);
    b = criavet(n);
    x = criavet(n);
    for(int i = 0; i < n; i++){
        b[i] = baux2[i];
        for(int j = 0; j < n; j++){
            A[i][j] = Aaux2[i][j];
        }
    }
    printf("\nMatriz:\n");
    exibeMatriz(n, A);
    printf("\nVetor b:\n");
    exibeVetor(n, b);
    gauss(n, A, b, x);
    printf("\nSolucao: \n");
    exibeVetor(n, x);
    printf("\n");
    liberamat(n, A);
    liberavet(b);
    liberavet(x);
    return 0;
}


 