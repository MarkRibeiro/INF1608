//Aluno: Arthur Ozorio e Mark Ribeiro
//Matrícula: 1810334 e 1612043
#include"pendulo.h"

double Theta(double t, double theta0){
    return theta0*cos(sqrt(G/L)*t);
}

double ThetaLinha(double theta){
    return -(G/L)*sin(theta);
}

double PeriodSimplified(){
    return 2*PI*sqrt(L/G);
}

double PeriodRK(double theta0, double h, double tol, int mode){
    int count = 0;
    double v1, v2 = 0, T, t1 = 0, t2 = 0;
    while (count < 10){
        v1 = v2;
        t1 = t2;

        if(mode == 0)
        {
            t2 = RungeKutta(t1, h, &theta0, &v2);
        }
        else
        {
            t2 = RungeKuttaAdapt(t1, h, &theta0, &v2, tol);
        }
        
        if (v1*v2 < 0){
            count += 1;           
        }
    }
    T = 2 * (t1 + (fabs(v1)/(fabs(v1)+fabs(v2))) * (t2 - t1));
    return T/10;
}

double RungeKutta(double t0, double h, double *theta, double *v){
    double kt1, kt2, kt3, kt4;
    double kv1, kv2, kv3, kv4;

    kt1 = h*(*v);
    kv1 = h*ThetaLinha(*theta);

    kt2 = h*(*v + kv1/2);
    kv2 = h*ThetaLinha(*theta + kt1/2);


    kt3 = h*(*v + kv2/2);
    kv3 = h*ThetaLinha(*theta + kt2/2);

    kt4 = h*(*v + kv3);
    kv4 = h*ThetaLinha(*theta + kt3);

    *theta = *theta+(kt1+2*kt2+2*kt3+kt4)/6.0;
    *v = *v+(kv1+2*kv2+2*kv3+kv4)/6.0;

    return t0+h;
}

double RungeKuttaAdapt(double t0, double h, double *theta, double *v, double tol){

    double thetai = *theta;
    double vi = *v;
    double t1, delta, alpha;

    t1 = RungeKutta(t0, h, &thetai, &vi);

    delta = fabs(thetai - *theta);

    alpha = sqrt(tol/delta);

    if(alpha < 1.0f)
    {
        return RungeKuttaAdapt(t0, h * alpha, theta, v, tol);
    }

    *theta = thetai;
    *v = vi;

    return t1;
}

double anguloMax(double tol)
{
    double a = 0, b = PI/2, c = 0, erro;

    erro = (b-a)/2;
    while(erro > tol)
    {
        c = (a+b)/2;

		if(fabs(PeriodSimplified() - PeriodRK(c, 0.01, tol, 1))<0.001)
			a = c;
		else
			b = c;
		
		erro = (b-a)/2;
    }
    
    return (a + b)/2;
}