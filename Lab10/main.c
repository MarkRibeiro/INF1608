#include<stdio.h>
#include<stdlib.h>
#include"metiter.h"

#define TOL 1.0e-7
#define RELAX 1.1

void printaVetor(double *x, int n){
    printf("[");
    for(int i=0; i<n;i++)
    {
        if(i == n-1) {
            printf("%g",x[i]);
        }
        else {
            printf("%g, ",x[i]);
        }
    }
    printf("]\n");
}

void zeraVetor(double *x, int n){
    for(int i=0;i<n;i++)
    {
        x[i]=0;
    }
}

void resultados(char f, int t, int n, double **A, double *b, double *x){
    int iters;
    if(f == 'g'){
        iters = gauss_seidel(n,A,b,x,TOL);
        printf("\n--GaussSeidel--");
    }
    if(f == 's'){
        iters = SOR(n,A,b,x,TOL, RELAX);
        printf("\n--SOR--");
    }

    if(t < 3){
        printf("Problema %d--\n", t);
    }
    else {
        printf("Linhas Trocadas--\n");
    }
    
    printf("iteracoes: %d\n",iters);
    printf("solucao encontrada: ");
    printaVetor(x, n);
    zeraVetor(x, n);
}

void teste1(){
    int n = 2;
    int t = 1;
    double x[2] = {0,0};
    double b[2] = {5,5};
    double A0[2] = {3,1};
    double A1[2] = {1,2};
    double **A = malloc(2*sizeof(double*));
    A[0]=A0;
    A[1]=A1;

    resultados('g', t, n, A, b, x);
    resultados('s', t, n, A, b, x);
    free(A);
}

void teste2(){
    int n = 6;
    int t = 2;
    double x[6] = {0,0,0,0,0,0};
    double b[6] = {2.5,1.5,1,1,1.5,2.5};
    double A0[6] = {3,-1,0,0,0,0.5};
    double A1[6] = {-1,3,-1,0,0.5,0};
    double A2[6] = {0,-1,3,-1,0,0};
    double A3[6] = {0,0,-1,3,-1,0};
    double A4[6] = {0,0.5,0,-1,3,-1};
    double A5[6] = {0.5,0,0,0,-1,3};
    double **A = malloc(6*sizeof(double*));
    A[0]=A0;
    A[1]=A1;
    A[2]=A2;
    A[3]=A3;
    A[4]=A4;
    A[5]=A5;

    resultados('g', t, n, A, b, x);
    resultados('s', t, n, A, b, x);
    free(A);
}

void teste3(){
    int n = 6;
    int t = 3;
    double x[6] = {0,0,0,0,0,0};
    double b[6] = {2.5,1.5,1,1,1.5,2.5};
    double A0[6] = {3,-1,0,0,0,0.5};
    double A1[6] = {-1,3,-1,0,0.5,0};
    double A2[6] = {0,-1,3,-1,0,0};
    double A3[6] = {0,0,-1,3,-1,0};
    double A4[6] = {0,0.5,0,-1,3,-1};
    double A5[6] = {0.5,0,0,0,-1,3};
    double **A = malloc(6*sizeof(double*));
    A[0]=A5;
    A[1]=A1;
    A[2]=A2;
    A[3]=A3;
    A[4]=A4;
    A[5]=A0;

    resultados('g', t, n, A, b, x);
    resultados('s', t, n, A, b, x);
    free(A);
}

int main()
{
    teste1();
    teste2();
    teste3();

    return 0;
}