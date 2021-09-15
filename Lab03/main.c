#include<stdio.h>
#include<stdlib.h>
#include"matriz.h"
#include"sislinear.h"
#define N1 3
#define N2 6
void printaVetInt(int* v, int n){
    printf("[");
    for(int i = 0; i<n; i++){
        if(i+1 >= n){
            printf("%d", v[i]);
        }
        else {
            printf("%d, ", v[i]);
        }
    }
    printf("]\n");
}

void printaVetDouble(double* v, int n){
    printf("[");
    for(int i = 0; i<n; i++){
        if(i+1 >= n){
            printf("%.2f", v[i]);
        }
        else {
            printf("%.2f, ", v[i]);
        }
    }
    printf("]\n");
}

void printaMat(double** v, int n){
    for(int i = 0; i<n; i++){
        printaVetDouble(v[i], n);
    }
}

int main (){
    double **A; 
    double *b, *x;

    printf("TESTE 1: MATRIZ 3X3\n");
    A = (double**) malloc (N1*sizeof(double*));
    for(int i=0; i<N1; i++){
        A[i] = (double*) malloc (N1*sizeof(double));
    }
    b = (double*) malloc (N1*sizeof(double));
    x = (double*) malloc (N1*sizeof(double));

    A[0][0] = 1.0;
    A[0][1] = 2.0;
    A[0][2] = -1.0;

    A[1][0] = 2.0;
    A[1][1] = 1.0;
    A[1][2] = -2.0;

    A[2][0] = -3.0;
    A[2][1] = 1.0;
    A[2][2] = 1.0;

    b[0] = 3.0;
    b[1] = 3.0;
    b[2] = -6.0;

    x[0] = 0.0;
    x[1] = 0.0;
    x[2] = 0.0;  

    printf("\nMatriz A antes:\n");
    printaMat(A, N1);

    printf("\nVetor b:\n");
    printaVetDouble(b, N1);

    gauss(N1, A, b, x);

    printf("\nMatriz A depois:\n");
    printaMat(A, N1);

    printf("\nVetor solução:\n");
    printaVetDouble(x, N1);

    /**********************************************/
    printf("\nTESTE 2: MATRIZ 6X6\n");
    A = (double**) malloc (N2*sizeof(double*));
    for(int i=0; i<N2; i++){
        A[i] = (double*) malloc (N2*sizeof(double));
    }
    b = (double*) malloc (N2*sizeof(double));
    x = (double*) malloc (N2*sizeof(double));

    A[0][0] = 3.0;
    A[0][1] = -1.0;
    A[0][2] = 0.0;
    A[0][3] = 0.0;
    A[0][4] = 0.0;
    A[0][5] = 0.5;

    A[1][0] = -1.0;
    A[1][1] = 3.0;
    A[1][2] = -1.0;
    A[1][3] = 0.0;
    A[1][4] = 0.5;
    A[1][5] = 0;

    A[2][0] = 0.0;
    A[2][1] = -1.0;
    A[2][2] = 3.0;
    A[2][3] = -1.0;
    A[2][4] = 0.0;
    A[2][5] = 0.0;

    A[3][0] = 0.0;
    A[3][1] = 0.0;
    A[3][2] = -1.0;
    A[3][3] = 3.0;
    A[3][4] = -1.0;
    A[3][5] = 0.0;

    A[4][0] = 0.0;
    A[4][1] = 0.5;
    A[4][2] = 0.0;
    A[4][3] = -1.0;
    A[4][4] = 3.0;
    A[4][5] = -1.0;

    A[5][0] = 0.5;
    A[5][1] = 0.0;
    A[5][2] = 0.0;
    A[5][3] = 0.0;
    A[5][4] = -1.0;
    A[5][5] = 3.0;

    b[0] = 2.5;
    b[1] = 1.5;
    b[2] = 1.0;
    b[3] = 1.0;
    b[4] = 1.5;
    b[5] = 2.5;

    x[0] = 0.0;
    x[1] = 0.0;
    x[2] = 0.0;
    x[3] = 0.0;
    x[4] = 0.0;
    x[5] = 0.0; 

    printf("\nMatriz A antes:\n");
    printaMat(A, N2);

    printf("\nVetor b:\n");
    printaVetDouble(b, N2);

    gauss(N2, A, b, x);

    printf("\nMatriz A depois:\n");
    printaMat(A, N2);

    printf("\nVetor solução:\n");
    printaVetDouble(x, N2);

    return 0;
}