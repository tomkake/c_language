#include <stdio.h>
#include <string.h>
#include <mpi.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    /* code */
    const int server = 0;
    float value,value_sum,value2,value_avg;
    int num_proc,my_rank,mpi_err_code;
    //MPI start
    mpi_err_code = MPI_Init(&argc,&argv);
    mpi_err_code = MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
    mpi_err_code = MPI_Comm_size(MPI_COMM_WORLD,&num_proc);
    value_sum = 0.0;
    value_avg = 0.0;
    value = pow(my_rank,my_rank);
    value2 = pow(my_rank,my_rank) / num_proc;
    mpi_err_code = MPI_Reduce(&value,&value_sum,1,MPI_FLOAT,MPI_SUM,server,MPI_COMM_WORLD);
    mpi_err_code = MPI_Reduce(&value2,&value_avg,1,MPI_FLOAT,MPI_SUM,server,MPI_COMM_WORLD);
    if(my_rank == server){
    printf("%d : reduce value_sum = %f , value_avg = %f \n",my_rank,value_sum,value_avg);
    }
    mpi_err_code = MPI_Finalize();
    return 0;
}
