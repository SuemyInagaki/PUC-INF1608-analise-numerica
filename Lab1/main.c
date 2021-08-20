#include <stdio.h>
#include "taylor.h"
#include <math.h>
#define PI 3.1415926535897932384

void testa(double x);
//gcc main.c matriz.c -o matriz
int main(){
    testa(PI/10.0);
    testa(PI/8.0);
    testa(PI/6.0);
    testa(PI/4.0);
    testa(PI/3.0);
    printf("\nA tan1 é melhor!!\n");
    return 0;
}

void testa(double x){
    double t1, t2, t, erro1, erro2;
    printf("\n\nTeste x = %.4f\n", x);
    t1 = tan1(x);
    t2 = tan2(x);
    t = tan(x);
    erro1 = (fabs(t1 - t)/fabs(t))*100;
    erro2 = (fabs(t2 - t)/fabs(t))*100;
    printf("tan1(%.6f) = %.16g, erro = %.4f%c\n", x, t1, erro1, '%');
    printf("tan2(%.6f) = %.16g, erro = %.4f%c\n", x, t2, erro2, '%');
    printf("tan(%.6f)  = %.16g\n", x, t);
}