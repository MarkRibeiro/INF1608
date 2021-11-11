#include<stdio.h>
#include<stdlib.h>
#include"metiter.h"

int main (){
    int n = 1;
    double tol = 2, w = 3;
    double *b = (double*)malloc(sizeof(double)); 
    double *x = (double*)malloc(sizeof(double)); 
    double **A = (double**)malloc(sizeof(double*)*n);; 
    for (int i=0;i<n;i++){
        A[i] = (double*)malloc(sizeof(double));
    }
    
    int p1 = diagonal_dominante(n, A);
    int p2 = gauss_seidel(n, A, b, x, tol);
    int p3 = SOR(n, A, b, x, tol, w);

    printf("%d, %d, %d\n", p1, p2, p3);

    return 0;
}