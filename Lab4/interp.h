/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 4 - 14/09/2021
Interpolação de Polinomios
Nota: 10.0
*/
#ifndef INTERP_H
#define INTERP_H

// Funcao que retorna n amostras espacadas regularmente no intervalo [a, b], onde xi[0] = a, 
// xi[n−1] = b e os demais valores sao regularmente distribuıdos no intervalo. A funcao calcula
// as amostras xi e os valores yi = f(xi), preenchendo os vetores xi e yi pre-alocados, passados
// como parametros.

void regular (int n, double a, double b, double (*f) (double x), double* xi, double* yi);

// funcao que retorna as n amostras de Chebyshev para a aproximacao de uma funcao, dentro do 
// intervalo [a, b]. A funcao deve calcular as amostras xi e os valores yi = f(xi), preenchendo 
// os vetores xi e yi pre-alocados, passados como parametros.

void chebyshev (int n, double a, double b, double (*f) (double x), double* xi, double* yi);

// Funcao para avaliar o polinomio interpolante de Lagrange em um ponto
// x dado. A funcao recebe como parametros o conjunto de pontos e o valor de
// x, retornando o valor avaliado.
double lagrange (int n, double* xi, double* yi, double x);
#endif
