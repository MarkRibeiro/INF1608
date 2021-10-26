#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"interp.h"
#define PI 3.1415926535897932
#define N1 3
#define N2 5
#define N3 7
#define N4 9

double f1(double x){    
    return (1/(0.5*sqrt(2*PI)))*exp((-1.0/2.0)*pow(((x-0.0)/0.5), 2));
}

int main (){
    double a = -2, b = 2, x;
    double *rx, *ry, *cx, *cy;

    rx = (double*) malloc(N1*sizeof(double));
    ry = (double*) malloc(N1*sizeof(double));
    cx = (double*) malloc(N1*sizeof(double));
    cy = (double*) malloc(N1*sizeof(double));
    x = 1.5;

    regular(N1, a, b, f1, rx, ry);
    chebyshev(N1, a, b, f1, cx, cy);
    printf("Ponto: %.2f\nAmostras: %d\nMetodo: regular\nResultado: %f\n\n",x, N1, lagrange(N1, rx, ry, x));
    printf("Ponto: %.2f\nAmostras: %d\nMetodo: chebyshev\nResultado: %f\n",x, N1, lagrange(N1, cx, cy, x));
    printf("f(%.2f) = %f\n\n", x, f1(x));



/**********************************************/
    rx = (double*) malloc(N2*sizeof(double));
    ry = (double*) malloc(N2*sizeof(double));
    cx = (double*) malloc(N2*sizeof(double));
    cy = (double*) malloc(N2*sizeof(double));
    x = 1.5;

    regular(N2, a, b, f1, rx, ry);
    chebyshev(N2, a, b, f1, cx, cy);
    printf("Ponto: %.2f\nAmostras: %d\nMetodo: regular\nResultado: %f\n\n",x, N2, lagrange(N2, rx, ry, x));
    printf("Ponto: %.2f\nAmostras: %d\nMetodo: chebyshev\nResultado: %f\n",x, N2, lagrange(N2, cx, cy, x));
    printf("f(%.2f) = %f\n\n", x, f1(x));

/**********************************************/
    rx = (double*) malloc(N3*sizeof(double));
    ry = (double*) malloc(N3*sizeof(double));
    cx = (double*) malloc(N3*sizeof(double));
    cy = (double*) malloc(N3*sizeof(double));
    x = 0.5;

    regular(N3, a, b, f1, rx, ry);
    chebyshev(N3, a, b, f1, cx, cy);
    printf("Ponto: %.2f\nAmostras: %d\nMetodo: regular\nResultado: %f\n\n",x, N3, lagrange(N3, rx, ry, x));
    printf("Ponto: %.2f\nAmostras: %d\nMetodo: chebyshev\nResultado: %f\n",x, N3, lagrange(N3, cx, cy, x));
    printf("f(%.2f) = %f\n\n", x, f1(x));

/**********************************************/
    rx = (double*) malloc(N4*sizeof(double));
    ry = (double*) malloc(N4*sizeof(double));
    cx = (double*) malloc(N4*sizeof(double));
    cy = (double*) malloc(N4*sizeof(double));
    x = 0.5;

    regular(N4, a, b, f1, rx, ry);
    chebyshev(N4, a, b, f1, cx, cy);
    printf("Ponto: %.2f\nAmostras: %d\nMetodo: regular\nResultado: %f\n\n",x, N4, lagrange(N4, rx, ry, x));
    printf("Ponto: %.2f\nAmostras: %d\nMetodo: chebyshev\nResultado: %f\n",x, N4, lagrange(N4, cx, cy, x));
    printf("f(%.2f) = %f\n\n", x, f1(x));

    return 0;
}