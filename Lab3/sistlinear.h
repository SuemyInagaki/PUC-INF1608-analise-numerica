/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 3 - 02/09/2021
Sistema Linear
Nota: 10.0
*/
#ifndef SISTLINEAR_H
#define SISTLINEAR_H

// funcao que recebe como parametros uma matriz quadrada A, de
// dimensao n×n, e faz a fatoracao A = LU. As matrizes L e U sao armazenadas
// no espaco de memoria da matriz A, sobrescrevendo os valores dos elementos de A.
// A diagonal da matriz L (com valores iguais a 1) nao e armazenada. A funcao
// preenche o vetor de permutacao p, ja alocado, tambem recebido como parametro

void fatoracao (int n, double** A, int* p);

// funcao que recebe como entrada a matriz A fatorada (matriz LU), 
// de dimensao n×n, o vetor de permutacao p e um vetor independente b,
// e preenche o vetor solucao x, ja alocado, tambem recebido como parametro. 
// A matriz fatorada opera sobre o vetor independente permutado, b[p[i]].
void substituicao (int n, double** A, int* p, double* b, double* x);

// funcao que resolve um sistema linear. Recebe como parametros a 
// matriz A original, de dimensao n × n, e um vetor independente b,
// e preenche o vetor solucao x, ja alocado, tambem recebido como parametro. 
// Essa funcao usa as funcoes dos itens anteriores, alocando e depois liberando
// eventuais estruturas auxiliares
void gauss (int n, double** A, double* b, double* x);

#endif