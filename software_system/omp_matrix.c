#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
int ** create_matrix(int n){
    int ** matrix;

    matrix = malloc(sizeof(int *) * n);
    int rnd = rand() % 64 + 1;
    #pragma omp parallel for
    for (int i=0;i<n;i++) {
        matrix[i] = malloc(sizeof(int) * n);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            /* code */
            matrix[i][j] = rnd;
        }
    }
    return matrix;
}

int **calc_matrix(int ** A,int ** B,int n ){
    int ** matrixC;
    int tmp = 0;
    matrixC = malloc(sizeof(int *) * n);
    #pragma omp parallel for
    for (int i=0;i<n;i++) {
        matrixC[i] = malloc(sizeof(int) * n);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            /* code */
            tmp = 0;
            for ( int k = 0; k < n; k++)
            {
                /* code */
                tmp = tmp + A[i][k] * B[k][j];
                matrixC[i][j] = tmp;
            }

        }
    }
    return matrixC;
}

void free_matrix(int ** matrix,int n){
    for (int i=0;i<n;i++) {
        free(matrix[i]);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    int **matrixA;
    int **matrixB;
    int **matrixC;
    if(argc == 1){
        n = 64;
    }else if (argc == 2)
    {
        /* code */
        n = atoi( argv[1] );
    }else
    {
        /* code */
        return 0;
    }
    double st, en;
    st = omp_get_wtime();
    matrixA=create_matrix(n);
    matrixB=create_matrix(n);
    matrixC=calc_matrix(matrixA,matrixB,n);
    en = omp_get_wtime();
    for (int m = 0; m < n; m++)
    {
        for (int j = 0; j < n; j++)
        {
            /* code */
            printf("%d\n",matrixC[m][j]);
        }

    }
    printf("%lf\n",(en-st));
    free_matrix(matrixA,n);
    free_matrix(matrixB,n);
    free_matrix(matrixC,n);
    return 0;
}
