#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char const *argv[])
{
    const int max_message_length = 100;
    const int server_rank = 0;
    char message[max_message_length + 1];
    MPI_Status status;
    int my_rank;
    int num_proc;
    int source;
    int destination;
    int tag = 0;
    int mpi_error_code;

    //MPI start
    mpi_error_code = MPI_Init(&argc,&argv);
    mpi_error_code = MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
    mpi_error_code = MPI_Comm_size(MPI_COMM_WORLD,&num_proc);
    printf("%d : server_rank,%d : my_rank",server_rank,my_rank);
    if (my_rank != server_rank)
    {
        /* code */
        sprintf(message,"Greeting from process # %d\n",my_rank);
        destination = server_rank;
        mpi_error_code = MPI_Send(message,strlen(message) + 1,MPI_CHAR,destination,tag,MPI_COMM_WORLD);


    }else
    {
        /* code */
        for ( source = 0; source < num_proc; source++)
        {
            /* code */
            if(source != server_rank){
                mpi_error_code = MPI_Recv(message,max_message_length + 1,MPI_CHAR,source,tag,MPI_COMM_WORLD,&status);
                fprintf(stderr,"%s\n",message);
            }
        }

    }

    mpi_error_code = MPI_Finalize();
    return 0;
}