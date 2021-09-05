/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 1 - 19/08/2021
Série de Taylor
Nota: 10.0
*/
#include "taylor.h"

double tan1 (double x){
    return x*(1.0 + (x*x/3.0)*(1.0 + 2.0*x*x/5.0));
}

double tan2 (double x){
    return (x*(1.0 - x*x/6.0))/(1 - x*x/2.0);
}
