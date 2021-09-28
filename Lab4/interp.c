/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 4 - 14/09/2021
Interpolação de Polinomios
Nota: 10.0
*/

#include "interp.h"
#include <math.h>
#define PI 3.1415926535897932384

void regular (int n, double a, double b, double (*f) (double x), double* xi, double* yi){
    xi[0] = a;
    xi[n-1] = b;
    yi[0] = f(a);
    yi[n-1] = f(b);
    double tam = (b - a)/(n-1);
    for(int i = 1; i < n-1; i++){
        xi[i] = xi[i-1] + tam;
        yi[i] = f(xi[i]);
    }
}

void chebyshev (int n, double a, double b, double (*f) (double x), double* xi, double* yi){
    int beta = 1;
    for(int i = 0; i < n; i++){
        xi[i] = (b-a)*cos(beta*PI/(2*n))/2.0 + (a + b)/2;
        yi[i] = f(xi[i]);
        beta += 2;
    }
}

double lagrange (int n, double* xi, double* yi, double x){
    double y = 0;
    double L = 1.0;
    for(int i = 0; i < n; i++){
        L = 1.0;
        for(int j = 0; j < n; j++){
            if(j != i){
                L = L*(x - xi[j])/(xi[i] - xi[j]);
            }
        }
        y += yi[i]*L;
    }
    return y;
}

