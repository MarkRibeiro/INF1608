//Aluno: Mark Ribeiro
//Matrícula: 1612043
#include<stdio.h>
#include<math.h>
#include"ode.h"

int chamadas;

double f1 (double t, double y){
    chamadas+=1;
    return (t*y) + (t*t*t);
}

int main (){
    double t0 = 0; 
    double t1 = 1.2;
    double h = 0.001;
    double y0 = -1; 
    double tol = 1.0e-12;
    double y1 = exp(t1*t1/2)-t1*t1-2;

    chamadas=0;
    double res1 = RungeKutta(t0,t1,h,y0,f1);
    printf("*****Runge Kutta t=%.1f*****\n", t1);
    printf("Valor encontrado: %f\n",res1);
    printf("Erro relativo: %g\n",fabs(res1-y1)/y1);
    printf("Avaliacoes: %d\n\n",chamadas);

    chamadas=0;
    double res2 = RungeKuttaAcoplado(t0,t1,y0,f1,tol);
    printf("*****Runge Kutta Acoplado t=%.1f*****\n", t1);
    printf("Valor encontrado: %g\n",res2);
    printf("Erro relativo: %g\n",fabs(res2-y1)/y1);
    printf("Avaliacoes: %d\n\n",chamadas);

    t1 = 2.4;
    y1 = exp(t1*t1/2)-t1*t1-2;
    chamadas=0;
    res1 = RungeKutta(t0,t1,h,y0,f1);
    printf("*****Runge Kutta t=%.1f*****\n", t1);
    printf("Valor encontrado: %f\n",res1);
    printf("Erro relativo: %g\n",fabs(res1-y1)/y1);
    printf("Avaliacoes: %d\n\n",chamadas);

    chamadas=0;
    res2 = RungeKuttaAcoplado(t0,t1,y0,f1,tol);
    printf("*****Runge Kutta Acoplado t=%.1f*****\n", t1);
    printf("Valor encontrado: %g\n",res2);
    printf("Erro relativo: %g\n",fabs(res2-y1)/y1);
    printf("Avaliacoes: %d\n\n",chamadas);

    t1 = 5.0;
    y1 = exp(t1*t1/2)-t1*t1-2;
    chamadas=0;
    res1 = RungeKutta(t0,t1,h,y0,f1);
    printf("*****Runge Kutta t=%.1f*****\n", t1);
    printf("Valor encontrado: %f\n",res1);
    printf("Erro relativo: %g\n",fabs(res1-y1)/y1);
    printf("Avaliacoes: %d\n\n",chamadas);

    chamadas=0;
    res2 = RungeKuttaAcoplado(t0,t1,y0,f1,tol);
    printf("*****Runge Kutta Acoplado t=%.1f*****\n", t1);
    printf("Valor encontrado: %g\n",res2);
    printf("Erro relativo: %g\n",fabs(res2-y1)/y1);
    printf("Avaliacoes: %d\n",chamadas);

    return 0;
}
