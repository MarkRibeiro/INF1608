//Aluno: Mark Ribeiro
//Matrícula: 1612043
#include<stdio.h>
#include<math.h>
#include"ode.h"

double RungeKutta(double t0, double t1, double h, double y0, double (*f) (double t, double y)){
    double t=t0;
    double y=y0;
    while((t1-t) >= h/2)
    {
        double k1 = h*f(t,y);
        double k2 = h*f(t+h/2,y+k1/2);
        double k3 = h*f(t+h/2,y+k2/2);
        double k4 = h*f(t+h,y+k3);
        y = y+(k1+2*k2+2*k3+k4)/6.0;
        if(t+h>t1){
            h = t1-t;
        }
        t = t+h;
    }
    return y;
}

double RungeKuttaAcoplado(double t0, double t1, double y0, double (*f) (double t, double y), double tol){
    double hi = 1.0e-7;
    double ti = t0;
    double yi = y0;
    
    //Tabela de Cash-Karp
    double a2 = 1.0/5.0, a3 = 3.0/10.00, a4 = 3.0/5.0, a5 = 1.0, a6 = 7.0/8.0;
    double b21 = 1.0/5.0;
    double b31 = 3.0/40.0, b32 = 9.0/40.0; 
    double b41 = 3.0/10.0, b42 = -9.0/10.0, b43 = 6.0/5.0;
    double b51 = -11.0/54.0, b52 = 5.0/2.0, b53 = -70.0/27.0, b54 = 35.0/27.0;
    double b61 = 1631.0/55296.0, b62 = 175.0/512.0, b63 = 575.0/13824.0, b64 = 44275.0/110592.0, b65 = 253.0/4096.0;
    double c1 = 37.0/378.0, c2 = 0.0, c3 = 250.0/621.0, c4 = 125.0/594.0, c5 = 0.0, c6 = 512.0/1771.0;
    double cs1 = 2825.0/27648.0, cs2 = 0, cs3 = 18575.0/48384.0, cs4 = 13525.0/55296.0, cs5 = 277.0/14336.0, cs6 = 1.0/4.0;
    
    double k1, k2, k3, k4, k5, k6;

    while((t1-ti) >= hi/2){
        if(ti+hi > t1){
            hi = t1-ti;
        }

        k1 = hi*f(ti, yi);
        k2 = hi*f(ti + a2*hi, yi + b21*k1);
        k3 = hi*f(ti + a3*hi, yi + b31*k1 + b32*k2);
        k4 = hi*f(ti + a4*hi, yi + b41*k1 + b42*k2 + b43*k3);
        k5 = hi*f(ti + a5*hi, yi + b51*k1 + b52*k2 + b53*k3 + b54*k4);
        k6 = hi*f(ti + a6*hi, yi + b61*k1 + b62*k2 + b63*k3 + b64*k4 + b65*k5);

        double yp1 = yi + (c1*k1 + c2*k2 + c3*k3 + c4*k4 + c5*k5 + c6*k6);
        double ysp1 = yi + (cs1*k1 + cs2*k2 + cs3*k3 + cs4*k4 + cs5*k5 + cs6*k6);
        double delta = fabs(yp1 - ysp1);
        double fator = pow((tol/delta), 0.2);

        if(fator>=1){
            ti = ti + hi;
            yi = yp1;
            hi = fmin(1.2, fator)*hi;
        }
        else {
            hi = 0.9*fator*hi;
        }
    }
    return yi;
}