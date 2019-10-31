#include <math.h>
#include <stdio.h>
void example(int n, int m, float *a, float *b, float *y)
{
    int i;
    #pragma omp parallel
    {
        #pragma omp for nowait
        for (i = 1; i < n; i++)
            //個々のbの更新が次に使われているから、,一番初めはnowaitで待たなくても良いけど
            b[i] = (a[i] + a[i - 1]) / 2.0;
        #pragma omp for
        for (i= 0; i < m; i++)
            y[i] = sqrt(b[i - 1]);
    }
}


int main(int argc, char const *argv[])
{
    float a[3], b[3] ={0}, y[3]={0};
    for (int i = 0; i < 3; i++)
    {
        /* code */
        a[i] = (float)i+1;
    }
    example(3, 3, a, b, y);
     for (int i = 0; i < 3; i++)
    {
        /* code */
        printf("%lf\n",b[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        /* code */
        printf("%lf\n",y[i]);
    }
    
    return 0;
}