//Aluno: Arthur Ozorio e Mark Ribeiro
//Matrícula: 1810334 e 1612043
#include<stdio.h>
#include<math.h>
#include<sys/time.h>

#define G 9.81
#define L 10
#define PI 3.1415926535897932

double Theta(double t, double theta0);

double ThetaLinha(double theta);

double PeriodSimplified();

double PeriodRK(double theta0, double h, int mode);

double RungeKutta(double t0, double h, double *theta, double *v);

double RungeKuttaAdapt(double t0, double h, double *theta, double *v, double tol);