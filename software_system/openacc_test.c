#include <stdio.h>
int main(int argc, char const *argv[])
{
    const int N = 10;
    float a[N],b[N];
    for (int i = 0; i < N; i++)
    {
        /* code */
        a[i] = (float)(i+1);
        b[i] = 0.0f;
    }
    #pragma acc kernels
    for (int i = 0; i < N; i++)
    {
        /* code */
        b[i] = a[i];
    }
    for (int i = 0; i < N; i++)
    {
        /* code */
        printf("b[%d] = %.5f",i,b[i]);
    }
    
     
    return 0;
}
