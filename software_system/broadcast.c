#include <stdio.h>
#include <string.h>
#include <mpi.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    const int server = 0;
    const int source = server;
    int my_rank;
    int num_proc;
    int tag = 0;
    int mpi_error_code;

    //set up server
    float *array = (float*)NULL;
    int length,index;

    //MPI start
    mpi_error_code = MPI_Init(&argc, &argv);
    mpi_error_code = MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    mpi_error_code = MPI_Comm_size(MPI_COMM_WORLD, &num_proc);
    if (my_rank == server)
    {
        /* code */
        printf("%d\n",my_rank);
        scanf("%d\n", &length);
        array = (float *)malloc(sizeof(float) * length);
        for (index = 0; index < length; index++)
        {
            /* code */
            array[index] = 0.0;
        }
    }
    if (num_proc > 1)
    {
        /* code */
        mpi_error_code = MPI_Bcast(&length, 1, MPI_INTEGER, source, MPI_COMM_WORLD);
        if (my_rank != server)
        {
            /* code */
            array = (float *)malloc(sizeof(float) * length);
        }
        mpi_error_code = MPI_Bcast(array, length, MPI_INTEGER, source, MPI_COMM_WORLD);
        printf("%d : broadcast length = %d\n", my_rank, length);
    }
    mpi_error_code = MPI_Finalize();
    return 0;
}