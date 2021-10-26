//Aluno: Mark Ribeiro
//Matrícula: 1612043
#include<stdio.h>
#include<math.h>
#include"trapezio.h"

#define PI 3.1415926535897932

double f1(double x){
    return x/sqrt(pow(x, 2)+9);
}

double f2(double x){
    return exp(-pow(x, 2));
}

double f3(double x){
    return log(cos(x)+sin(x));
}

int main(){
    double tol;

    tol = 1e-1;
    printf("********TOLERANCIA = %.0e********\n", tol);
    printf("f1: %.8f\n", adaptiva(0, 1, f1, tol));
    printf("f2: %.8f\n", adaptiva(0, 3, f2, tol) * 2/sqrt(PI));
    printf("f3: %.8f\n", adaptiva(0, PI/2, f3, tol));
    printf("\n");

    tol = 1e-2;
    printf("********TOLERANCIA = %.0e********\n", tol);
    printf("f1: %.8f\n", adaptiva(0, 1, f1, tol));
    printf("f2: %.8f\n", adaptiva(0, 3, f2, tol) * 2/sqrt(PI));
    printf("f3: %.8f\n", adaptiva(0, PI/2, f3, tol));
    printf("\n");

    tol = 1e-4;
    printf("********TOLERANCIA = %.0e********\n", tol);
    printf("f1: %.8f\n", adaptiva(0, 1, f1, tol));
    printf("f2: %.8f\n", adaptiva(0, 3, f2, tol) * 2/sqrt(PI));
    printf("f3: %.8f\n", adaptiva(0, PI/2, f3, tol));
    printf("\n");

    tol = 1e-8;
    printf("********TOLERANCIA = %.0e********\n", tol);
    printf("f1: %.8f\n", adaptiva(0, 1, f1, tol));
    printf("f2: %.8f\n", adaptiva(0, 3, f2, tol) * 2/sqrt(PI));
    printf("f3: %.8f\n", adaptiva(0, PI/2, f3, tol));
    printf("\n");

    printf("Probabilidade(1): %.2f%%\n", probabilidade(1)*100);
    printf("Probabilidade(2): %.2f%%\n", probabilidade(2)*100);
    printf("Probabilidade(3): %.2f%%\n", probabilidade(3)*100);
    return 0;
}