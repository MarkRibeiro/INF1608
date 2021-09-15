#include<stdio.h>
#include<math.h>
#include"raiz.h"

#define TOL 0.000000005

int secante(double x0, double x1, double (*f) (double x), double* r){
    int i = 0;
    double fx0 = f(x0);
    double fx1 = f(x1);
    while(fabs(fx1-fx0)>TOL && i < 50){
        *r = x1 - ((fx1*(x1-x0))/(fx1-fx0));
        x0 = x1;
        x1 = *r;
        fx0 = fx1;
        fx1 = f(x1);
        i += 1;
    }
    *r = (x0+x1)/2;
    return i;
}

int IQI(double x0, double x1, double x2, double (*f) (double x), double* r){
    int i = 0;
    double fx0 = f(x0);
    double fx1 = f(x1);
    double fx2 = f(x2);
    *r = x2;
    while(fabs(fx2)>TOL && i < 50){
        double detA = (
        ((fx0*fx0)*(fx1)*(1))+
        ((fx0)*(1)*(fx2*fx2))+
        ((1)*(fx1*fx1)*(fx2))) - (
        ((fx0*fx0)*(1)*(fx2))+
        ((fx0)*(fx1*fx1)*(1))+
        ((1)*(fx1)*(fx2*fx2))
        );
        double detAc = (
        ((fx0*fx0)*(fx1)*(x2))+
        ((fx0)*(x1)*(fx2*fx2))+
        ((x0)*(fx1*fx1)*(fx2))) - (
        ((fx0*fx0)*(x1)*(fx2))+
        ((fx0)*(fx1*fx1)*(x2))+
        ((x0)*(fx1)*(fx2*fx2))
        );
        *r = detAc/detA;
        x0 = x1;
        x1 = x2;
        x2 = *r;
        fx0 = fx1;
        fx1 = fx2;
        fx2 = f(x2);
        i += 1;
    }
    return i;
}