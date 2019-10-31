#include <stdio.h>
#include <omp.h>

int main()
{
    int i = 0;
#pragma omp parallel sections {
    for (i = 0; i < 20; i++)
    {
        printf("Hello : %d\n", omp_get_thread_num());
    }
}
}