#include <stdio.h>
#include <omp.h>
int main(int argc, char const *argv[])
{
    #pragma omp parallel
    #ifdef _OPENMP
    printf("Hello Wrold!");
    #else
    printf("Hello Wrold!2");
    #endif
    return 0;
}
