#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int number_of_process;
    int my_rank;
    int mpi_error_code;
    mpi_error_code = MPI_Init(&argc,&argv);
    mpi_error_code = MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
    mpi_error_code = MPI_Comm_size(MPI_COMM_WORLD,&number_of_process);
    printf("%d of %d: Hello ,World \n",my_rank,number_of_process);
    mpi_error_code = MPI_Finalize();

    return 0;
}