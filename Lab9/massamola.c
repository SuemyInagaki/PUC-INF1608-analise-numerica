/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 9 - 01/11/2021
Simulação Física
Nota: 10.0
*/

#include<math.h>
#include<stdio.h>
#define g 9.8
#define m 2.0
#define w 20.0
#define k 0.5
#define r 200
#define delta 0.002

void forca (double t, double x, double y, double* fx, double* fy){
    double fw = w*exp(-t/20.0);
    double modulo = sqrt(x*x + y*y);
    double kx = -k*(modulo - r)*x/modulo;
    double ky = -k*(modulo - r)*y/modulo;
    (*fy) = m*g + ky;
    (*fx) = fw + kx;
}

double evolui (double t, double h, double x, double y, double xp, double yp, double* xn, double* yn){
    double fx, fy;
    forca(t, x, y, &fx, &fy);
    (*xn) = x + (1-delta)*(x - xp) + h*h*fx/m;
    (*yn) = y + (1-delta)*(y - yp) + h*h*fy/m;
    return t+h;
}

void simula (double x0, double y0, double t_final, int n, double* x, double* y){
    double h = t_final/n;
    double t, xi, yi, xp, yp, xn, yn;
    xp = x0;
    yp = y0;
    xi = x0;
    yi = y0;
    t = 0.0;
    for(int i = 0; i < n; i++){
        t = evolui(t, h, xi, yi, xp, yp, &xn, &yn);
        xp = xi;
        yp = yi;
        xi = xn;
        yi = yn;
        x[i] = xn;
        y[i] = yn;
    }
}