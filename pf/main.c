//Aluno: Mark Ribeiro
//Matrícula: 1612043
#include"ode.h"

int main (){
    double theta = PI/180;
    double period;
    double h;

    printf("Periodo simplificado: \n");
    period = PeriodSimplified();
    printf("periodo: %f\n\n", period);

    h = 1e-2;
    printf("Periodo RK com h = 1e-2: \n");
    period = PeriodRK(theta, h);
    printf("periodo: %f\n\n", period);

    h = 1e-3;
    printf("Periodo RK com h = 1e-3: \n");
    period = PeriodRK(theta, h);
    printf("periodo: %f\n\n", period);

    h = 1e-4;
    printf("Periodo RK com h = 1e-4: \n");
    period = PeriodRK(theta, h);
    printf("periodo: %f\n\n", period);

    return 0;
}