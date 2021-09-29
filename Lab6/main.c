/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 6 - 28/09/2021
Metodos de Integração e Derivação

*/

//gcc main.c integral.c -lm -o integral

#include "integral.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define PI 3.1415926535897932384

static double f (double x){
    return cos(x) - 2*sin(x);
}

static double g (double x){
    return x/sqrt(x*x+9);
}

static double h (double x){
    return x*x*log(x);
}

static double i (double x){
    return x*x*sin(x);
}

int main(){
    int n; char c = '%';
    double deri, inte, a, b, erro;
    printf("-------------------------\n");
    printf("Teste 1\n");
    printf("-------------------------\n");
    
    n = 2;
    deri = derivada(n, f, 0, 1e-6); 
    erro = fabs(deri + 2.0)*100;
    printf("n = %d, h = 10^-%d, x = 0.0\n", n, 6);
    printf("derivada = %f\n", deri);
    printf("erro = %f%c\n\n", erro, c);
    
    n = 4;
    deri = derivada(n, f, 0, 1e-6);
    erro = fabs(deri + 2.0)*100;
    printf("n = %d, h = 10^-%d, x = 0.0\n", n, 6);
    printf("derivada = %f\n", deri);
    printf("erro = %f%c\n\n", erro, c);

    n = 4;
    deri = derivada(n, f, 0, 1e-15);
    erro = fabs(deri + 2.0)*100;
    printf("n = %d, h = 10^-%d, x = 0.0\n", n, 15);
    printf("derivada = %f\n", deri);
    printf("erro = %f%c\n\n", erro, c);

    printf("-------------------------\n");
    printf("Teste 2\n");
    printf("-------------------------\n");
    n = 16;
    a = 0.0; b = 4.0;
    inte = trapezio(g, a, b, n);
    erro = fabs(inte - 2.0);
    printf("n = %d\n", n);
    printf("trapezio = %f\n", inte);
    printf("erro = %f%c\n\n", erro, c);
    
    inte = simpson(g, a, b, n);
    erro = fabs(inte - 2.0);
    printf("simpson = %f\n", inte);
    printf("erro = %f%c\n\n", erro, c);
    
    n = 32;
    inte = trapezio(g, a, b, n);
    erro = fabs(inte - 2.0);
    printf("n = %d\n", n);
    printf("trapezio = %f\n", inte);
    printf("erro = %f%c\n\n", erro, c);
    
    inte = simpson(g, a, b, n);
    erro = fabs(inte - 2.0);
    printf("simpson = %f\n", inte);
    printf("erro = %f%c\n\n", erro, c);

    printf("-------------------------\n");
    printf("Teste 3\n");
    printf("-------------------------\n");
    a = 1.0; b = 3.0;
    n = 16;
    inte = trapezio(h, a, b, n);
    erro = fabs(inte - 6.9986217091241);
    printf("n = %d\n", n);
    printf("trapezio = %f\n", inte);
    printf("erro = %f%c\n\n", erro, c);
    
    inte = simpson(h, a, b, n);
    erro = fabs(inte - 6.9986217091241);
    printf("simpson = %f\n", inte);
    printf("erro = %f%c\n\n", erro, c);
    
    n = 32;
    inte = trapezio(h, a, b, n);
    erro = fabs(inte - 6.9986217091241);
    printf("n = %d\n", n);
    printf("trapezio = %f\n", inte);
    printf("erro = %f%c\n\n", erro, c);
    
    inte = simpson(h, a, b, n);
    erro = fabs(inte - 6.9986217091241);
    printf("simpson = %f\n", inte);
    printf("erro = %f%c\n\n", erro, c);
    
    printf("-------------------------\n");
    printf("Teste 4\n");
    printf("-------------------------\n");
    a = 0; b = PI;
    n = 16;
    inte = trapezio(i, a, b, n);
    erro = fabs(inte - 5.8696044010894);
    printf("n = %d\n", n);
    printf("trapezio = %f\n", inte);
    printf("erro = %f%c\n\n", erro, c);
    
    inte = simpson(i, a, b, n);
    erro = fabs(inte - 5.8696044010894);
    printf("simpson = %f\n", inte);
    printf("erro = %f%c\n\n", erro, c);
    
    n = 32;
    inte = trapezio(i, a, b, n);
    erro = fabs(inte - 5.8696044010894);
    printf("n = %d\n", n);
    printf("trapezio = %f\n", inte);
    printf("erro = %f%c\n\n", erro, c);
    
    inte = simpson(i, a, b, n);
    erro = fabs(inte - 5.8696044010894);
    printf("simpson = %f\n", inte);
    printf("erro = %f%c\n\n", erro, c);
    return 0;
}