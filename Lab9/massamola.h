/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 9 - 01/11/2021
Simulação Física
Nota: 10.0
*/
#ifndef MASSAMOLA_H
#define MASSAMOLA_H

// funcao que receba como parametros o tempo t e a posicao corrente do
// corpo (x, y). A funcao calcula os valores da forca total (gravidade + vento + mola)
// atuante e preenche os ponteiros tambem passados como parametros:
void forca (double t, double x, double y, double* fx, double* fy);


// Usando o metodo de Verlet indicado acima, dada uma configuracao no instante t, calcule a
// nova posicao do corpo no instante t + h. A funcao deve receber como parametros o tempo
// corrente t, o passo de integracao h, a posicao corrente (x, y) e a posi¸c˜ao anterior (xp, yp).
// A funcao deve preencher a nova posicao nos endere¸cos de memoria tambem passados como
// parametros e retornar o tempo atualizado (t + h):
double evolui (double t, double h, double x, double y, double xp, double yp, double* xn, double* yn);

// Usando a funcao evolui, escreva uma funcao que preencha um vetor de posicoes do corpo
// ao longo do tempo. Sua funcao recebe como parametros a posicao inicial (x0, y0), o tempo
// total de simulacao tf inal e o numero de iteracoes n, fazendo o passo de integracao valer
// h = t_final/n. A funcao deve preencher os vetores x e y, previamente alocados, de dimensao
// n, com as posicoes do corpo nos instantes h, 2h, ..., nh.
void simula (double x0, double y0, double t_final, int n, double* x, double* y);

#endif