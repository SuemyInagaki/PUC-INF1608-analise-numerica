/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 7 - 11/10/2021
Metodos de Integração Adaptativa
*/

#include<math.h>
#include<stdlib.h>
#include"trapezio.h"
#define PI 3.1415926535897932384

// Implemente uma funcao para Integracao Adaptativa segundo a Regra do Trapezio. Sua
// funcao deve receber o intervalo de integracao, a funcao e a tolerancia de erro desejada, e
// retornar o valor total da integral no intervalo dentro da tolerancia.
double adaptiva (double a, double b, double (*f) (double x), double tol){
    double m = (a+b)/2;
    double fa = f(a);
    double fb = f(b);
    double fm = f(m);
    double tab = (b-a)*(fa + fb)/2;
    double tam = (m - a)*(fm + fa)/2;
    double tmb = (b - m)*(fm + fb)/2;
    double delta = tab - (tam + tmb);
    if (fabs(delta) > 3*tol){
        return (adaptiva(a, m, f, tol/2) + adaptiva(m, b, f, tol/2));
    }
    else{
        return (tam + tmb - delta/3);
    }
}

static double g (double x){
    return exp(-x*x/2);
}
// Implemente uma funcao que receba como parametro o valor de σ e retorne a probabilidade,
// usando a funcao do item anterior, com precisao de 8 dıgitos. 
double probabilidade (double sigma){
    double p = 1.0/(sqrt(2*PI))*adaptiva(-sigma, sigma, g, 1e-8/2);
    return p;
}