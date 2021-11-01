/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 9 - 01/11/2021
Simulação Física
*/

#include"massamola.h"
#include<math.h>
#include<stdio.h>
#include<stdlib.h>

//gcc main.c massamola.c -lm -o massamola
int main(){
    double h = 0.1;
    double t_final = 100;
    double n = t_final/h;
    double x0 = 200.0;
    double y0 = 0.0;
    double*x = (double*)malloc(n*sizeof(double));
    double*y = (double*)malloc(n*sizeof(double));
    double fx, fy;
    // for(int i = 0; i < 20; i++){
    //     evolui(i, 0.1, x0+i, y0+i, x0+(i-1), y0+(i-1), &fx, &fy);
        
    // }
    simula(x0, y0, t_final, n, x, y);
    for(int i = 0; i < n; i++){
        printf("%f, %f\n", x[i], y[i]);
    }
    return 0;
}