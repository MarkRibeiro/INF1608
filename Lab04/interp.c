#include<stdio.h>
#include<math.h>
#define PI 3.1415926535897932

void regular(int n, double a, double b, double (*f) (double x), double* xi, double* yi){
    float passo = (b - a)/(n - 1);

    for(int i=0;i<n;i++){
        xi[i] = i*passo+a;
        yi[i] = f(xi[i]);
    }
}

void chebyshev(int n, double a, double b, double (*f) (double x), double* xi, double* yi){
    for(int i=0;i<n;i++){
        double beta = 2*i+1;
        xi[i] = ((b-a)/2.0)*cos(((beta*PI)/(2.0*n)))+((a+b)/2.0);
        yi[i] = f(xi[i]);
    }
}

double lagrange(int n, double* xi, double* yi, double x){
    double ret = 0.0;

    for(int i = 0; i<n; i++){
        double l = 1.0;
        for(int j = 0; j<n; j++){
            if(i != j){
                l = l * (x-xi[j])/(xi[i]-xi[j]);
            }
        }
        ret = ret + (yi[i] * l);
    }
    return ret;
}