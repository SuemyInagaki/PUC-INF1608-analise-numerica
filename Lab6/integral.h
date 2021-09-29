/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 6 - 28/09/2021
Metodos de Integração e Derivação

*/
#ifndef INTEGRAL_H
#define INTEGRAL_H

// Implemente uma funcao (recursiva) que retorne o valor da derivada numerica correspondente
//  a um metodo de ordem n de uma funcao no ponto x, com passo h, tendo como base no metodo 
// de segunda ordem, usando extrapolacao de Richardson. (com n ≥ 2)
double derivada (int n, double (*f) (double x), double x, double h);

// Implemente uma funco que calcule a integral composta do intervalo de a a b
// considerando n passos de integracao, isto e, considerando h = (b − a)/n.
double trapezio (double (*f) (double), double a, double b, int n);

// Implemente uma funcao que calcule a integral composta do intervalo de a a b
// considerando n passos de integracao, isto e, considerando h = (b − a)/n. 
double simpson (double (*f) (double), double a, double b, int n);
#endif