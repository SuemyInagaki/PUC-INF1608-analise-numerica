/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 8 - 23/10/2021
EDO
*/
#ifndef ODE_H
#define ODE_H


// Sua funcao deve receber como parametros o tempo inicial t0, o tempo 
// final t1, o passo de integracao h, o valor inicial y(t0) e a funcao 
// derivada f(t, y(t)), tendo como retorno o valor no tempo final y(t1),
// seguindo o prototipo:

double RungeKutta (double t0, double t1, double h, double y0, double (*f) (double t, double y));


// Implemente o metodo de Runge Kutta acoplado, conforme apresentado acima. Sua
// funcao deve receber como parametros o tempo inicial t0, o tempo final t1, o valor
// inicial y(t0), a funcao derivada f(t, y(t)) e a tolerancia do erro relativo tol, 
// tendo como retorno o valor no tempo final y(t1). Como valor de passo inicial, deve-se
// adotar h0 = 10−7. A funcao deve ter o seguinte o prototipo:

double RungeKuttaAcoplado (double t0, double t1, double y0, double (*f) (double t, double y), double tol);
#endif