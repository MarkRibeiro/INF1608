//Aluno: Mark Ribeiro
//Matrícula: 1612043
#include"ode.h"

int main (){
    double theta[] = {PI/180, PI/90, PI/45, PI/15, PI/5, PI/2}; //1 grau, 2 graus, 4 graus, 12 graus, 36 graus, 90 graus
    int n = sizeof(theta)/sizeof(theta[0]);
    double period;
    double h;

    printf("*****Periodo simplificado*****\n");
    period = PeriodSimplified();
    printf("periodo: %f\n", period);

    h = 1e-2;
    printf("\n*****Periodo RK com h = 1e-2*****\n");
    for(int i=0;i<n;i++){
        period = PeriodRK(theta[i], h);
        printf("periodo com theta = %.0f°: %f\n", (theta[i]*180)/PI, period);
    }

    h = 1e-3;
    printf("\n*****Periodo RK com h = 1e-3*****\n");
    for(int i=0;i<n;i++){
        period = PeriodRK(theta[i], h);
        printf("periodo com theta = %.0f°: %f\n", (theta[i]*180)/PI, period);
    }

    h = 1e-4;
    printf("\n*****Periodo RK com h = 1e-4*****\n");
    for(int i=0;i<n;i++){
        period = PeriodRK(theta[i], h);
        printf("periodo com theta = %.0f°: %f\n", (theta[i]*180)/PI, period);
    }

    return 0;
}