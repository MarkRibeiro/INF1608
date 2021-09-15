#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void fatoracao(int n, double** A, int* p){
    int aux;
    for(int i=0; i<n; i++){
        p[i] = i;
    }

    for(int linha=0; linha<n-1;linha++){
        aux = linha;
        for(int coluna=linha+1; coluna<n; coluna++){
            if(fabs(A[coluna][linha]) > fabs(A[aux][linha])){
                aux = coluna;
            }
        }
        if(aux!=linha){
            for(int i=0; i<n;i++){
                double dt = A[linha][i];
                A[linha][i] = A[aux][i];
                A[aux][i] = dt;
            }

            int it = p[linha];
            p[linha] = p[aux];
            p[aux] = it;
        }

        for(int j=linha+1; j<n; j++){
            double index = A[j][linha]/A[linha][linha];
            for(int x = linha+1; x<n; x++){
                A[j][x] = A[j][x] - index*A[linha][x];
            }
            A[j][linha] = index;
        }
    }
}

void substituicao(int n, double** A, int* p, double* b, double* x){

    for(int i=0; i<n; i++)
    {
        double s=0.0;
        for(int j=0; j<i; j++)
        {
            s+=A[i][j]*x[j];
        }
        x[i]=(b[p[i]]-s);
    }

    for(int i=n-1; i>=0; i--)
    {
        double s=0.0;
        for(int j=n-1; j>i; j--)
        {
            s+=A[i][j]*x[j];
        }
        x[i]=(x[i]-s)/A[i][i];
    }
}

void gauss(int n, double** A, double* b, double* x){
    int *p = (int*) malloc(n*sizeof(int));
    fatoracao(n, A, p);
    substituicao(n, A, p, b, x);
    free(p);
}