/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 2 - 26/08/2021
*/
#ifndef RAIZ_H
#define RAIZ_H

// metodo da secante para determinacao de raizes da funcao f(x) 
int secante (double x0, double x1, double (*f) (double x), double* r);

// metodo da interpolacao quadratica inversa (IQI) para determinacao de raızes da funcao f(x)
int IQI (double x0, double x1, double x2, double (*f) (double x), double* r);

#endif