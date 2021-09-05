/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 2 - 26/08/2021
Aproximação de Raizes
Nota: 10.0
*/

#include "raiz.h"
#include <math.h>

int secante (double x0, double x1, double (*f) (double x), double* r){
    double x2;
    double fx0 = f(x0);
    double fx1 = f(x1);
    int i = 0;
    while(i < 50){
        if(fabs(fx1 - fx0) < 1e-15){
            x2 = (x0 + x1)/2.0;
        }
        else{
            x2 = x1 - (fx1 * (x1 - x0))/(fx1 - fx0);
        }
        if(fabs(x2 - x1)/fabs(x2) < 0.5*1e-8){
            *r = x2;
            return i;
        }
        x0 = x1;
        fx0 = fx1;
        x1 = x2;
        fx1 = f(x2);
        i++; 
    }
    return 0;
}

int IQI (double x0, double x1, double x2, double (*f) (double x), double* r){
    double x3, detA, detAc;
    double fx0 = f(x0);
    double fx1 = f(x1);
    double fx2 = f(x2);
    int i = 0;
    while(i < 50){
        detA = -(fx1 - fx0)*(fx2 - fx0)*(fx2 - fx1);
        detAc = fx0*fx0*(fx1*x2 - x1*fx2) - fx0*(fx1*fx1*x2 - x1*fx2*fx2) + x0*(fx1*fx1*fx2 - fx1*fx2*fx2);
        x3 = detAc/detA;
        if(fabs(x3 - x2)/fabs(x3) < 0.5*1e-8){
            *r = x3;
            return i;
        }
        x0 = x1;
        fx0 = fx1;
        x1 = x2;
        fx1 = fx2;
        x2 = x3;
        fx2 = f(x3);
        i++;
    }
    return 0;
}