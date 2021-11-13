#include<stdio.h>
#include<math.h>
#include"metiter.h"
#include"matriz.h"

int diagonal_dominante(int n, double** A)
{
    for(int i=0; i<n; i++)
    {
        double total=0;
        double diag;

        for(int j=0; j<n; j++)
        {
            if(i == j)
            {
                diag=fabs(A[i][j]);
            }
            else
            {
                total+=fabs(A[i][j]);
            }
            if(diag<=total)
            {
                return 0;
            }
        }
        return 1;
    }
    return 1;
} 

int gauss_seidel(int n, double** A, double* b, double* x, double tol)
{
    if(!diagonal_dominante(n,A))
    {
        return 0;
    }

    int iters=0;
    double* dif = criavet(n);

    do
    {
        for(int i=0; i<n; i++)
        {
            double tot=0;
            for(int j=0; j<n; j++)
            {
                if(i!=j)
                {
                    tot+=A[i][j]*x[j];
                }
            }
            tot=b[i]-tot;
            double xNew=(tot)/A[i][i];
            dif[i]=xNew-x[i];
            x[i]=xNew;
        }
        iters++;
    }while(norma2(n,dif) > tol);
    liberavet(dif);
    return iters;
}

int SOR(int n, double** A, double* b, double* x, double tol, double w)
{
    if(!diagonal_dominante(n,A))
    {
        return 0;
    }

    int iters=0;
    double* dif = criavet(n);

    do
    {
        for(int i=0; i<n; i++)
        {
            double tot=0;
            for(int j=0; j<n; j++)
            {
                if(i!=j)
                {
                    tot+=A[i][j]*x[j];
                }
            }
            tot=b[i]-tot;
            double xNew=(tot)/A[i][i];
            dif[i]=xNew-x[i];
            x[i]=(1-w)*x[i] + w*xNew;
        }
        iters++;
    }while(norma2(n,dif) > tol);
    liberavet(dif);
    return iters;
}