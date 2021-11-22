/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 10 - 09/11/2021
Métodos Iterativos para Sistemas Lineares
*/

#ifndef METITER_H
#define METITER_H

// Funcao que verifica se uma dada matriz A de dimensao n × n e
// estritamente diagonal dominante. A funçao recebe a matriz como parametro 
// e deve retornar 1 se a matriz for estritamente diagonal dominante ou 0, caso contrario.
int diagonal_dominante (int n, double** A);


// Escreva uma funçao que receba como parametros a dimensao do problema n, a matriz
// A, o vetor independente b, a aproximaçao inicial da soluçao x e a tolerancia de erro
// aceitavel. A iteraçao deve terminar quando a norma-2 do vetor resıduo (r = b − Ax)
// tiver valor menor ou igual a tolerancia. A funçao deve armazenar a soluçao final em
// x e retornar o numero de iteraçoes efetuado. Se a matrix A nao for estritamente
// diagonal dominante, a funçao deve retornar zero. O prototipo da funçao e dado por:
int gauss_seidel (int n, double** A, double* b, double* x, double tol);

// Seguindo a mesma interface, implemente o metodo iterativo de Gauss-Seidel com
// sobre-relaxamento (w > 1.0). Isto e, a funçao deve avaliar inicialmente xk+1 com o
// metodo de Gauss-Seidel e entao ajustar xk+1 com a formula do relaxamento:
// A funçao tambem deve receber o fator de relaxamento como parˆametro adicional. O
// prototipo da funçao e dado por:
int SOR (int n, double** A, double* b, double* x, double tol, double w);

#endif