/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 8 - 23/10/2021
EDO
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double RungeKutta (double t0, double t1, double h, double y0, double (*f) (double t, double y)){
    double t = t0;
    double y = y0;
    double k1, k2, k3, k4;
    int i = 0;
    while(t < t1 - h/2){
        k1 = h*f(t, y);
        k2 = h*f(t+h/2, y + k1/2);
        k3 = h*f(t+h/2, y + k2/2);
        k4 = h*f(t+h, y + k3);
        y = y + (k1 + 2*k2 + 2*k3 + k4)/6;
        t = t + h;
        i+=4;
    }
    printf("n de avaliacoes da funcao = %d\n", i);
    return y;
}


double* oneStep(double t, double y, double h, double (*f) (double t, double y), double tol){
    double a[6] = {0, 1.0/5.0, 3.0/10.0, 3.0/5.0, 1.0, 7.0/8.0};
    double b[6][5] = {{0, 0, 0, 0, 0}, {1.0/5.0, 0, 0, 0, 0}, {3.0/40.0, 9.0/40.0, 0, 0, 0}, {3.0/10.0, -9.0/10.0, 6.0/5.0, 0, 0}, {-11.0/54.0, 5.0/2.0, -70.0/27.0, 35.0/27.0, 0}, {1631.0/55296.0, 175.0/512.0, 575.0/13824.0, 44274.0/110592.0, 253.0/4096.0}};
    double c[6] = {37.0/378.0, 0.0, 250.0/621.0, 125.0/594.0, 0.0, 512.0/1771.0};
    double c_[6] = {2825.0/27648.0, 0.0, 18575.0/48384.0, 13525.0/55296.0, 277.0/14336.0, 1.0/4.0};
    double y_, delta, y1, fator;
    double k1, k2, k3, k4, k5, k6;
    k1 = h*f(t, y);
    k2 = h*f(t+a[1]*h, y + b[1][0]*k1);
    k3 = h*f(t+a[2]*h, y + b[2][0]*k1 + b[2][1]*k2);
    k4 = h*f(t+a[3]*h, y + b[3][0]*k1 + b[3][1]*k2 + b[3][2]*k3);
    k5 = h*f(t+a[4]*h, y + b[4][0]*k1 + b[4][1]*k2 + b[4][2]*k3 + b[4][3]*k4);
    k6 = h*f(t+a[5]*h, y + b[5][0]*k1 + b[5][1]*k2 + b[5][2]*k3 + b[5][3]*k4 + b[5][4]*k5);
    y1 = y + c[0]*k1 + c[1]*k2 + c[2]*k3 + c[3]*k4 + c[4]*k5 + c[5]*k6;
    y_ = y + c_[0]*k1 + c_[1]*k2 + c_[2]*k3 + c_[3]*k4 + c_[4]*k5 + c_[5]*k6;
    delta = fabs(y1 - y_);
    fator = pow(tol/delta, 1.0/5);
    if(fator >= 1.0){
        t = t + h;
        h = fmin(1.2, fator)*h;
        y = y1;
        double* l = (double*)malloc(3*sizeof(double));
        l[0] = y;
        l[1] = t;
        l[2] = h;
        return l;
    }
    else{
        h = 0.9*fator*h;
        return oneStep(t, y, h, f, tol);
    }
}

double RungeKuttaAcoplado (double t0, double t1, double y0, double (*f) (double t, double y), double tol){
    double t = t0;
    double y = y0;
    double h = 1e-7;
    double* l;
    int i = 0;
    while(t < t1){
        if(t + h > t1){
            h = t1 - t;
        }
        l = oneStep(t, y, h, f, tol);
        y = l[0];
        t = l[1];
        h = l[2];
        i+=6;
        free(l);
    }
    printf("n de avaliacoes da funcao = %d\n", i);
    return y;
}
