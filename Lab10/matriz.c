#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"matriz.h"

double* criavet(int n)
{
    return (double*) malloc(n * sizeof(double));
}

void liberavet(double* v)
{
    free(v);
}

double norma2(int n, const double* v)
{

    double norma2=0;
    for(int i=0;i<n;i++)
    {
        norma2+=v[i]*v[i];
    }

    return sqrt(norma2);
}