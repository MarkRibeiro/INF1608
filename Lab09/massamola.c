#include<stdio.h>
#include<math.h>
#include"massamola.h"

void forca(double t, double x, double y, double *fx, double *fy){
    double k = 0.5;
    double r = 200;
    double m = 2.0;
    double g[2] = {0.0, 9.8};
    double w[2] = {20.0, 0.0};

    //fx
    double fgx = m*g[0];
    double fwx = w[0]*exp(-t/20);
    double fkx = -k*(fabs(sqrt(x*x + y*y))-r)*(x/fabs(sqrt(x*x + y*y)));
    *fx = fgx + fwx +fkx;

    //fy
    double fgy = m*g[1];
    double fwy = w[1]*exp(-t/20);
    double fky = -k*(fabs(sqrt(x*x + y*y))-r)*(y/fabs(sqrt(x*x + y*y)));
    *fy = fgy + fwy +fky;
}

double evolui(double t, double h, double x, double y, double xp, double yp, double* xn, double* yn){
    double delta = 0.002;
    double m = 2.0;
    double fx, fy;

    forca(t, x, y, &fx, &fy);
    *xn = x + (1 - delta)*(x-xp)+((h*h)*(fx/m));
    *yn = y + (1 - delta)*(y-yp)+((h*h)*(fy/m));

    return t+h;
}


void simula(double x0, double y0, double t_final, int n, double* x, double* y){
    double xp = x0, yp = y0;
    double xi = x0, yi = y0;
    double t = 0;
    int i = 0;

    while(t<t_final){
        t = evolui(t, t_final/n, xi, yi, xp, yp, &x[i], &y[i]);
        xp = xi;
        yp = yi;
        xi = x[i];
        yi = y[i];
        i += 1;
    }
}