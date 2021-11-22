/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 7 - 11/10/2021
Metodos de Integração Adaptativa
Nota: 10.0
*/
#ifndef TRAPEZIO_H
#define TRAPEZIO_H

// Implemente uma funcao para Integracao Adaptativa segundo a Regra do Trapezio. Sua
// funcao deve receber o intervalo de integracao, a funcao e a tolerancia de erro desejada, e
// retornar o valor total da derivada no intervalo dentro da tolerancia.
double adaptiva (double a, double b, double (*f) (double x), double tol);

// Implemente uma funcao que receba como parametro o valor de σ e retorne a probabilidade,
// usando a funcao do item anterior, com precisao de 8 dıgitos. 
double probabilidade (double sigma);

#endif