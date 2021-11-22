/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 12 - 22/11/2021
Otimização
*/

#include<math.h>
#include<stdio.h>
#include"otimizacao.h"


int SecaoAurea (double a, double b, double (*f) (double x), double tol, double* xmin){
    double g = (sqrt(5.0) - 1.0)/2.0;
    double x1, x2, fx1, fx2, aux, faux;
    x1 = a + (1-g)*(b-a);
    x2 = a + (g)*(b-a);
    fx1 = f(x1);
    fx2 = f(x2);
    int i = 0;
    while(fabs(x2 - x1)/2 > tol){
        i++;
        if(fx1 < fx2){
            b = x2;
            x2 = x1;
            fx2 = fx1;
            x1 = a + (1-g)*(b-a); //devo alterar o b antes ou depois de avaliar?
            fx1 = f(x1);
        }
        else{
            a = x1;
            x1 = x2;
            fx1 = fx2;
            x2 = a + g*(b-a);
            fx2 = f(x2);
        }
    }
    *xmin = (x1 + x2)/2.0;
    return i;
}

int MIPS (double r, double s, double t, double (*f) (double x), double tol, double* xmin){
    double fs, fr, ft, x, den;
    fs = f(s);
    fr = f(r);
    ft = f(t);
    // den = (2.0*((s-r)*(ft-fs)) - (fs - fr)*(t-s));
    // if(fabs(den) < 1e-10){
    //     x = (r + s + t)/3.0;
    // }else{
    //     x = (r + s)/2.0 - ((fs - fr)*(t-r)*(t-s))/den;
    // }
    int i = 0;
    
    while(fabs(fs - ft) > tol || i <= 5){
        // printf("fabs = %f\n", fabs(fs - ft));
        i++;
        if(i == 51){
            return 0;
        }
        den = 2.0*((s-r)*(ft-fs) - (fs - fr)*(t-s));
        if(fabs(den) < 1e-10){
            x = (r + s + t)/3.0;
        }else{
            x = (r + s)/2.0 - ((fs - fr)*(t-r)*(t-s))/den;
        }
        r = s;
        fr = fs;
        s = t;
        fs = ft;
        t = x;
        ft = f(x);
        // printf("xmin = %f\n", *xmin);
    }
    *xmin = (s + t)/2.0;
    return i;
}