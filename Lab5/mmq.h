/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 5 - 21/09/2021
Metodo dos Minimos Quadrados
*/
#ifndef MMQ_H
#define MMQ_H

// Função que resolve o sistema Am×nxn = bm pelo metodo dos mınimos
// quadrados. A funcao cria (aloca dinamicamente) e retorna o vetor que
// representa a solucao aproximada
double* mmq (int m, int n, double** A, double* b);

// Funcao para calcular a norma-2 do resıduo
double mmq_norma2 (int m, int n, double** A, double* b, double* x);

// sando o metodo dos mınimos quadrados, escreva uma funcao que receba um con-
// junto de medicoes (ti, ci) e calcule os coeficientes a e b, preenchendo seus 
// valores nos enderecos de memoria recebidos como parametros. 
void ajuste (int n, double* t, double* c, double* a, double* b);
#endif