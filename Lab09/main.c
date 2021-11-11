#include<stdio.h>
#include<stdlib.h>
#include"massamola.h"
int main(){
    double h = 0.1, x0 = 200, y0 = 0, t_final = 100, n = t_final/h;
    double *x = (double*)malloc(sizeof(double)*n);
    double *y = (double*)malloc(sizeof(double)*n);

    simula(x0, y0, t_final, n, x, y);

    for (int i=0;i<n;i++){
        printf("%g %g\n",x[i], y[i]);
    }
}