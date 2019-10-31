#include <stdio.h>
#include <omp.h>

int main(int argc, char const *argv[])
{
    /* code */
    float i = 0;
    const int N = 100;
    float A[N],B[N],C[N];
    #pragma acc kernels
    for (int i = 0; i < N; i++)
    {
        /* code */
        B[i] = (float)(i+1);
        C[i] = (float)(i+1);
        A[i] = 0.0f;
    }
    #pragma acc kernels
    for (int i = 0; i < N; i++)
    {
        /* code */
        A[i] = B[i] * C[i];
    }
    for (int i = 0; i < N; i++)
    {
        /* code */
        printf("A[%d] = %.5f\n",i,A[i]);
    }
    return 0;
}
