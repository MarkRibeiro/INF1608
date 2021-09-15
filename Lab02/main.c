#include<stdio.h>
#include<math.h>
#include"raiz.h"

double f1(double x){
    return (x*x*x)+x-7;
}

double f2(double x){
    return (x*x*x*x)+x+1;
}

double f3(double m){
    return (((9.8*m)/15)*(1-exp(((-15)/(m))*9))-35);
}

void printaSecante(double x0, double x1, int i, double* r){
    printf("Método usado: Secante\n");
    printf("Chute x0=%.2f\n", x0);
    printf("Chute x1=%.2f\n", x1);
    printf("Numero de iterações: %d\n", i);
    printf("Raiz encontrada: %f\n", *r);
    printf("\n");
}

void printaIQI(double x0, double x1, double x2, int i, double* r){
    printf("Método usado: IQI\n");
    printf("Chute x0=%.2f\n", x0);
    printf("Chute x1=%.2f\n", x1);
    printf("Chute x2=%.2f\n", x2);
    printf("Numero de iterações: %d\n", i);
    printf("Raiz encontrada: %f\n", *r);
    printf("\n");
}

int main(void){
    double r;
    double x0;
    double x1;
    double x2;

    printf("*****Função testada: x^3+x-7*****\n");
    //chute 1
    x0 = -1;
    x1 = 3;
    x2 = 1;
    printaSecante(x0, x1, secante(x0, x1, f1, &r), &r);
    printaIQI(x0, x1, x2, IQI(x0, x1, x2, f1, &r), &r);

    //chute 2
    x0 = 1;
    x1 = 2;
    x2 = 1.5;
    printaSecante(x0, x1, secante(x0, x1, f1, &r), &r);
    printaIQI(x0, x1, x2, IQI(x0, x1, x2, f1, &r), &r);

    //chute 3
    x0 = 1.5;
    x1 = 2;
    x2 = 1.7;
    printaSecante(x0, x1, secante(x0, x1, f1, &r), &r);
    printaIQI(x0, x1, x2, IQI(x0, x1, x2, f1, &r), &r);

    printf("*****Função testada: x^4+x+1*****\n");
    //chute 4
    x0 = -1;
    x1 = 3;
    x2 = 1;
    printaSecante(x0, x1, secante(x0, x1, f2, &r), &r);
    printaIQI(x0, x1, x2, IQI(x0, x1, x2, f2, &r), &r);

    //chute 5
    x0 = 1;
    x1 = 2;
    x2 = 1.5;
    printaSecante(x0, x1, secante(x0, x1, f2, &r), &r);
    printaIQI(x0, x1, x2, IQI(x0, x1, x2, f2, &r), &r);

    //chute 6
    x0 = 1.5;
    x1 = 2;
    x2 = 1.7;
    printaSecante(x0, x1, secante(x0, x1, f2, &r), &r);
    printaIQI(x0, x1, x2, IQI(x0, x1, x2, f2, &r), &r);

    printf("*****Função testada: ((9.8*m)/15)*(1-exp(((-15)/(m))*9))*****\n");
    //chute 7
    x0 = 20;
    x1 = 200;
    x2 = 100;
    printaSecante(x0, x1, secante(x0, x1, f3, &r), &r);
    printaIQI(x0, x1, x2, IQI(x0, x1, x2, f3, &r), &r);

    //chute 8
    x0 = 40;
    x1 = 100;
    x2 = 80;
    printaSecante(x0, x1, secante(x0, x1, f3, &r), &r);
    printaIQI(x0, x1, x2, IQI(x0, x1, x2, f3, &r), &r);

    //chute 9
    x0 = 60;
    x1 = 300;
    x2 = 150;
    printaSecante(x0, x1, secante(x0, x1, f3, &r), &r);
    printaIQI(x0, x1, x2, IQI(x0, x1, x2, f3, &r), &r);
    
    return 0;
}