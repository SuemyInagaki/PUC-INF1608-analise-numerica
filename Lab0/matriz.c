/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 0 - 12/08/2021
*/
#include <stdlib.h>
#include<math.h>
#include "matriz.h"

double* criavet (int n){
    double* v = (double*)malloc(n*sizeof(double));
    if(v == NULL){
        exit(1);
    }
    return v;
}

void liberavet (double* v){
    free(v);
}

double escalar (int n, const double* v, const double* w){
    double resultado = 0.0;
    for(int i = 0; i < n; i++){
        resultado += v[i]*w[i];
    }
    return resultado;
}

double norma2 (int n, const double* v){
    double resultado = escalar(n, v, v);
    return sqrt(resultado);
}

void multvs (int n, const double* v, double s, double *w){
    for(int i = 0; i < n; i++){
        w[i] = s*v[i];
    }
}

double** criamat (int m, int n){
    double** M = (double**)malloc(m*sizeof(double*));
    if(M == NULL){
        exit(1);
    }
    for(int i = 0; i<m; i++){
        double* aux = (double*)malloc(n*sizeof(double));
        if(aux == NULL){
            exit(1);
        }
        M[i] = aux;
    }
    return M;
}

double** criamattri (int n){
    double** M = (double**)malloc(n*sizeof(double*));
    if(M == NULL){
        exit(1);
    }
    for(int i = 0; i < n; i++){
        double* aux = (double*)malloc((i+1)*sizeof(double));
        if(aux == NULL){
            exit(1);
        }
        M[i] = aux;
    }
    return M;
}

void liberamat (int m, double** A){
    for(int i = 0; i < m; i++){
        free(A[i]);
    }
    free(A);
}

void transposta (int m, int n, const double** A, double** T){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            T[j][i] = A[i][j];
        }
    }
}

void multmv (int m, int n, const double** A, const double* v, double* w){
    for(int i = 0; i < m; i++){
        w[i] = 0;
        for(int j = 0; j < n; j++){ 
            w[i] += A[i][j]*v[j]; 
        }
    }
}

void multmm (int m, int n, int q, const double** A, const double** B, double** C){
    for(int i = 0; i < m; i++){
        for(int k = 0; k < q; k++){
            C[i][k] = 0;
            for(int j = 0; j < n; j++){
                C[i][k] += A[i][j]*B[j][k];
            }
        }
    }
}

