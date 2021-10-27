/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 6 - 28/09/2021
Metodos de Integração e Derivação
Nota: 10.0
*/

#include "integral.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

double derivada (int n, double (*f) (double x), double x, double h){
    if(n < 2){
        printf("n deve ser maior que 2!\n");
        return -1;
    }
    else if(n == 2){
        return (f(x + h) - f(x - h))/(2*h);
    }
    else{
        //Calcular Fn+1 de h e de h/2
        double pot = pow(2, n);
        double Fh = derivada(n-1, f, x, h);
        double Fh2 = derivada(n-1, f, x, h/2);
        return (pot*Fh2 - Fh)/(pot - 1);
    }
}

// a, a+h, a+2h, ..., b

// i = 0, xi = a,     fxi = f(a),      fxih = f(a + h)
// i = 1, xi = a + h, fxi = f(a + h),  fxih = f(a + 2h)

double trapezio (double (*f) (double), double a, double b, int n){
    double h = (b-a)/n;
    double integral = 0.0;
    double xi = a;
    double fxih = f(a + h);
    double fxi = f(a);
    for(int i = 0; i < n; i++){
        integral += (h/2)*(fxi + fxih);
        xi += h;
        fxi = fxih;
        fxih = f(xi + h);
    }
    return integral;
}

double simpson (double (*f) (double), double a, double b, int n){
    double h = (b-a)/n;
    double integral = 0.0;
    double xi = a;
    double fxih = f(a + h);
    double fxih2 = f(a + h/2);
    double fxi = f(a);
    for(int i = 0; i < n; i++){
        integral += (h/6)*(fxi + 4*fxih2 + fxih);
        xi += h;
        fxi = fxih;
        fxih2 = f(xi + h/2);
        fxih = f(xi + h);
    }
    return integral;
}
