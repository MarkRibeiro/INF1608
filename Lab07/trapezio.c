//Aluno: Mark Ribeiro
//Matrícula: 1612043
#include<stdio.h>
#include<math.h>
#include"trapezio.h"

#define PI 3.1415926535897932

double f4(double x){
    return exp((-pow(x, 2))/2);
}

double adaptiva(double a, double b, double (*f)(double x), double tol){
    double c = (a+b)/2;
    double tab = (((b-a)/2)*(f(a)+f(b)));
    double tac = (((c-a)/2)*(f(a)+f(c)));
    double tcb = (((b-c)/2)*(f(c)+f(b)));
    double delta = tab - tac - tcb;

    if(tol > fabs(delta)/3){
        return tac + tcb - delta/3;
    }

    return adaptiva(a, c, f, tol/2) + adaptiva(c, b, f, tol/2);
}

double probabilidade(double sigma){
    return adaptiva(-sigma, sigma, f4, 1e-8) * 1/(sqrt(2*PI));
}