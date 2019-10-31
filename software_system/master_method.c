#include <stdio.h>
#include <omp.h>

void work1() {}
void work2() {}

void single_example()
{
#pragma omp parallel
    {
#pragma omp simple
        printf("Beggining work1 : \n");
        work1();
#pragma omp simple
        printf("Finishing work1 : \n");
#pragma omp simple
        printf("Finished work1 and begging work2 : \n");
        work2();
    }
}

int main()
{
    single_example();
    return 0;
}