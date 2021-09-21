/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 5 - 21/09/2021
Metodo dos Minimos Quadrados
*/

#include "sistlinear.h"
#include "matriz.h"
#include "mmq.h"
#include <math.h>
#include <stdlib.h>

double* mmq (int m, int n, double** A, double* b){
    double** T = criamat(n, m);
    transposta(m, n, A, T);
    double** C = criamat(n, n);
    multmm(n, m, n, T, A, C);
    double* w = criavet(n);
    multmv(n, m, T, b, w);
    double* x = criavet(n);
    gauss(n, C, w, x);
    liberamat(n, T);
    liberamat(n, C);
    liberavet(w);
    return x;
}

double mmq_norma2 (int m, int n, double** A, double* b, double* x){
    double norma = 0.0;
    double r;
    double* w = criavet(m);
    multmv(m, n, A, x, w);
    for(int i = 0; i < m; i++){
        r = (b[i] - w[i]);
        norma += r*r;
    }
    norma = sqrt(norma);
    liberavet(w);
    return norma;
}

void ajuste (int n, double* t, double* c, double* a, double* b){
    double** A = criamat(n, 2);
    double* vb = criavet(n);
    
    for(int i = 0; i < n; i++){
        A[i][0] = 1;
        A[i][1] = t[i];
        vb[i] = log(c[i]) - log(t[i]);
    }

    double* x = mmq(n, 2, A, vb);
    double k = x[0];
    (*a) = exp(k);
    (*b) = x[1];
    liberavet(x);
    liberavet(vb);
    liberamat(n, A);
}