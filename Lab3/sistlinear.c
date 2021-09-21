/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 3 - 02/09/2021
Sistema Linear
Nota: 10.0
*/

#include "sistlinear.h"
#include "matriz.h"
#include <math.h>
#include <stdlib.h>

void fatoracao (int n, double** A, int* p){
    int i, j, k, pivo, aux_pivo;
    double f, aux;
    for(j = 0; j < n-1; j++){
        pivo = j;
        for(k = j + 1; k < n; k++){
            if(fabs(A[k][j]) > fabs(A[pivo][j])){
                pivo = k;
            }
        }
        //troca a linha j com a linha pivo:
        if(pivo != j){
            // troca no vetor p
            aux_pivo = p[j];
            p[j] = p[pivo];
            p[pivo] = aux_pivo;
            // troca na matriz A
            for(k = 0; k < n; k++){
                aux = A[j][k];
                A[j][k] = A[pivo][k];
                A[pivo][k] = aux;
            }
        }
        for(i = j + 1; i < n; i++){
            f = A[i][j]/A[j][j];
            for(k = j + 1; k < n; k++){
                A[i][k] = A[i][k] - A[j][k]*f;  
            }
            A[i][j] = f;
        }
    }
}

void substituicao (int n, double** A, int* p, double* b, double* x){
    int i, j;
    double s;
    double* y = criavet(n);
    // substituicao progressiva
    for(i = 0; i < n; i++){
        s = 0;
        for(j = 0; j < i; j++){
            s += A[i][j]*y[j];
        }
        y[i] = (b[p[i]] - s); //a diagonal da L eh sempre 1
    }
    // retro-substituicao
    for(i = n-1; i >= 0; i--){
        s = 0;
        for(j = i + 1; j < n; j++){
            s += A[i][j]*x[j];
        }
        x[i] = (y[i] - s)/A[i][i];
    }
}

void gauss (int n, double** A, double* b, double* x){
    int* p = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++)
        p[i] = i;
    fatoracao(n, A, p);
    substituicao(n, A, p, b, x);
    free(p);
}