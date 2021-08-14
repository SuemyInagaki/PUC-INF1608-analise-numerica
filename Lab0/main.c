/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 0 - 12/08/2021

Para compilar
gcc main.c matriz.c -o matriz
*/

#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"


// Declaracao das funcoes de teste
double* testaCriavet(int n, double f);
void testaLiberavet(double* v);
void testaProdescalar(const double* v, const double* w, int n);
void testaNorma2(int n, const double* v);
void testaMultvs(int n, const double* v, double s);
double** testaCriamat(int m, int n, double f);
void testaCriamattri(int n);
void testaLiberamat(int m, int n, double** M);
void testaTransposta(int m, int n, const double** A);
void testaMultmv(int m, int n, const double** A, const double* v);
void testaMultmm(int m, int n, int q, const double** A, const double** B);


int main(){
    int tam = 3;
    double s = 4.0;
    int m = 4, n = 3;
    //testa as funcoes
    printf("Inicio dos testes\n");
    double* v = testaCriavet(tam, 0.0001);
    double* w = testaCriavet(tam, 0.3);
    testaProdescalar(v, w, tam);
    testaLiberavet(v);
    testaNorma2(tam, v);
    testaMultvs(tam, v, s);
    double** M = testaCriamat(m, n, 0.4);
    double** B = testaCriamat(n, m, 1);
    testaCriamattri(n);
    testaTransposta(m, n, M);
    testaMultmv(m, n, M, v);
    testaMultmm(m, n, m, M, B);
    testaLiberamat(m, n, M);
    testaLiberamat(n, m, B);
    printf("\nFim dos testes\n");
    return 0;
}

void exibeVetor(int n, const double* v){
    printf("[");
    for(int i = 0; i < n - 1; i++){
        printf("%lf ", v[i]);
    }
    printf("%lf]\n", v[n-1]);
}

void exibeMatriz(int m, int n, const double** M){
    for(int i = 0; i < m; i++){
        exibeVetor(n, M[i]);
    }
}

double* testaCriavet(int n, double f){
    printf("\nTeste da funcao criavet\n");
    double* v = criavet(n);
    //preenche vetor
    for(int i = 0; i < n; i++){
        v[i] = i*f;
    }
    exibeVetor(n, v);
    return v;
}
void testaLiberavet(double* v){
    printf("\nTeste da funcao liberavet\n");
    printf("Antes de liberar: %lf\n", v[1]);
    liberavet(v);
    printf("Depois de liberar: %lf\n", v[1]);
}

void testaProdescalar(const double* v, const double* w, int n){
    printf("\nTeste da funcao escalar\n");
    printf("vetores:\n");
    exibeVetor(n, v);
    exibeVetor(n, w);
    double res = escalar(n, v, w);
    printf("Produto escalar = %lf\n", res);
}

void testaNorma2(int n, const double* v){
    printf("\nTeste da funcao norma2\n");
    printf("vetor:\n");
    exibeVetor(n, v);
    double res = norma2(n, v);
    printf("Norma2 = %lf\n", res);
}

void testaMultvs(int n, const double* v, double s){
    printf("\nTeste da funcao multvs\n");
    printf("vetor:\n");
    exibeVetor(n, v);
    printf("escalar = %lf\n", s);
    double* w = criavet(n);
    multvs(n, v, s, w);
    printf("vetor resultante:\n");
    exibeVetor(n, w);
}

double** testaCriamat(int m, int n, double f){
    printf("\nTeste da funcao criamat\n");
    double** M = criamat(m, n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            M[i][j] = i+j+i*j*f;
        }
    }
    exibeMatriz(m, n, M);
    return M;
}

void exibeMatrizTri(int n, const double** M){
    for(int i = 0; i < n; i++){
        exibeVetor(i+1, M[i]);
    }
}

void testaCriamattri(int n){
    printf("\nTeste da funcao criamattri\n");
    double** M = criamattri(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < (i+1); j++){
            M[i][j] = i;
        }
    }
    exibeMatrizTri(n, M);
    liberamat(n, M);
}   

void testaLiberamat(int m, int n, double** M){
    printf("\nTeste da funcao liberamat\n");
    printf("Matriz antes de liberar:\n");
    exibeMatriz(m, n, M);
    liberamat(n, M);
    printf("Matriz depois de liberar:\n");
    exibeMatriz(m, n, M);
}

void testaTransposta(int m, int n, const double** A){
    printf("\nTeste da funcao transposta\n");
    double** T = criamat(n, m);
    transposta(m, n, A, T);
    printf("Matriz A:\n");
    exibeMatriz(m, n, A);
    printf("Matriz T:\n");
    exibeMatriz(n, m, T);
    liberamat(n, T);
}

void testaMultmv(int m, int n, const double** A, const double* v){
    printf("\nTeste da funcao multmv\n");
    double* w = criavet(m);
    multmv(m, n, A, v, w);
    printf("Vetor: ");
    exibeVetor(n, v);
    printf("Matriz: \n");
    exibeMatriz(m, n, A);
    printf("Vetor resultante: ");
    exibeVetor(m, w);
    liberavet(w);
}

void testaMultmm(int m, int n, int q, const double** A, const double** B){
    printf("\nTeste da funcao multmm\n");
    double** C = criamat(m, q);
    multmm(m, n, q, A, B, C);
    printf("Matriz 1:\n");
    exibeMatriz(m, n, A);
    printf("Matriz 2:\n");
    exibeMatriz(n, q, B);
    printf("Matriz resultante:\n");
    exibeMatriz(m, q, C);
    liberamat(q, C);
}