/*
Nome: Suemy Inagaki Pinheiro Fagundes
INF1608 - Analise Numerica
Lab 12 - 22/11/2021
Otimização
Nota: 10.0
*/
#ifndef OTIMIZACAO_H
#define OTIMIZACAO_H

// Implemente uma funcao que codifica o Metodo da Secao Aurea. Sua funcao deve 
// receber como parametros o intervalo inicial de busca, a funcao objetivo, a tolerancia
// de convergencia e um ponteiro xmin que deve ser preenchido com o valor de x onde a
// funcao tem valor mınimo dado pelo metodo. A funcao deve ainda retornar o numero
// de iteracoes executadas para se alcancar o resultado, seguindo o prototipo a seguir.
// Sua implementacao deve minimizar o numero de avaliacoes da funcao f(x).

int SecaoAurea (double a, double b, double (*f) (double x), double tol, double* xmin);


// Implemente uma funcao que codifica o Metodo da Interpolacao Parabolica Sucessiva.
// Sua funcao deve receber como parametros as estimativas iniciais, a funcao objetivo, a
// tolerancia de convergencia e um ponteiro xmin que deve ser preenchido com o valor de
// x onde a funcao tem valor mınimo dado pelo metodo. A funcao deve ainda retornar
// o numero de iteracoes executadas para se alcancar o resultado, seguindo o prototipo
// a seguir.
int MIPS (double r, double s, double t, double (*f) (double x), double tol, double* xmin);

#endif