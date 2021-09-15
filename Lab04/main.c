#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"interp.h"
#define PI 3.1415926535897932

double f1(double x){    
    return (1/(0.5*sqrt(2*PI)))*exp((-1.0/2.0)*pow(((x-0.0)/0.5), 2));
}

int main (){
    int n = 4;
    double a = -2, b = 2, x;
    double *xi = (double*) malloc(n*sizeof(double));
    double *yi = (double*) malloc(n*sizeof(double));

    //regular(n, a, b, f1, xi, yi);
    chebyshev(n, a, b, f1, xi, yi);
    //lagrange(n, xi, yi, x);

    return 0;
}