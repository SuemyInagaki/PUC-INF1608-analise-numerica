/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 2 - 26/08/2021
*/
// Nota: 10.0
//gcc main.c raiz.c -o raiz
#include <stdio.h>
#include <math.h>
#include "raiz.h"

static double g (double x){
    return x*(x*x*x + 1.0) + 1.0;
}

static double f (double x){
    return x*(x*x + 1.0) - 7.0;
}

static double massa(double x){
    return ((9.8*x/15)*(1-exp(-15*9/x)) - 35);
}
void exibeg();
void exibef();
void testaMassa(double x0, double x1, double x2, double (*f) (double x));
void testaSecante(double x0, double x1, double (*f) (double x));
void testaIQI(double x0, double x1, double x2, double (*f) (double x));
int main(){
    printf("\n******** Inicio dos testes ********\n");
    printf("\n-------------------------------");
    printf("\nTestar a convergencia:\n");
    printf("-------------------------------");
    printf("\nTeste a1, ");
    exibef();
    testaSecante(2.0, 2.25, f);
    testaIQI(2.0, 2.25, 3.0, f);
    printf("-------------------------------");
    printf("\nTeste a2, ");
    exibef();
    testaSecante(1.0, 2.0, f);
    testaIQI(1.0, 1.5, 2.0, f);
    printf("-------------------------------");
    printf("\nTeste a3, ");
    exibef();
    testaSecante(-1.0, 2.0, f);
    testaIQI(1.0, 2.0, 2.5, f);
    printf("-------------------------------");
    printf("\nTeste a4, ");
    exibef();
    testaSecante(-3.0, -2.0, f);
    testaIQI(1.0, 2.0, 4.0, f);
    printf("\n-------------------------------");
    printf("\nTestar a nao convergencia\n");
    printf("-------------------------------");
    printf("\nTeste b1, ");
    exibeg();
    testaSecante(-3.0, -2.0, g);
    testaIQI(1.0, 2.0, 2.5, g);
    printf("\n-------------------------------");
    printf("\nEncontrar a massa:\n");
    printf("-------------------------------");
    printf("\nTeste c1\n");
    testaMassa(-200, -100, 0, massa);
    printf("-------------------------------");
    printf("\nTeste c2\n");
    testaMassa(-1500, -1300, -1000, massa);
    printf("-------------------------------");
    printf("\nTeste c3\n");
    testaMassa(0, 50, 100, massa);
    printf("-------------------------------");
    return 0;
}
void testaSecante(double x0, double x1, double (*f) (double x)){
    double r;
    int q;
    q = secante(x0, x1, f, &r);
    printf("\nSECANTE\n");
    printf("x0 = %.3f, x1 = %.3f\n", x0, x1);
    if(q == 0){
        printf("Não convergiu!\n");
    }
    else{
        printf("Raiz encontrada: %.10g\nIteracoes: %d\n", r, q);
    }
}
void testaIQI(double x0, double x1, double x2, double (*f) (double x)){
    double r;
    int q;
    q = IQI(x0, x1, x2, f, &r);
    printf("\nIQI\n");
    printf("x0 = %.3f, x1 = %.3f, x2 = %.3f\n", x0, x1, x2);
    if(q == 0){
        printf("Não convergiu!\n");
    }
    else{
        printf("Raiz encontrada: %.10g\nIteracoes: %d\n", r, q);
    }
}

void testaMassa(double x0, double x1, double x2, double (*f) (double x)){
    double r1, r2;
    int q1, q2;
    q1 = secante(x0, x1, f, &r1);
    q2 = IQI(x0, x1, x2, f, &r2);
    printf("\nSECANTE\n");
    printf("x0 = %.3f, x1 = %.3f\n", x0, x1);
    if(q1 == 0){
        printf("Não convergiu!\n");
    }
    else{
        printf("Massa encontrada: %.10g\nIteracoes: %d\n", r1, q1);
    }
    printf("\nIQI\n");
    printf("x0 = %.3f, x1 = %.3f, x2 = %.3f\n", x0, x1, x2);
    if(q2 == 0){
        printf("Não convergiu!\n");
    }
    else{
        printf("Massa encontrada: %.10g\nIteracoes: %d\n", r2, q2);
    }
}
void exibeg(){
    printf("g(x) = x^4 + x + 1\n");
}
void exibef(){
    printf("f(x) = x^3 + x - 7\n");
}


 
