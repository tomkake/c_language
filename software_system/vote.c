#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>
#include <string.h>

int Random(int minvalue, int maxvalue)
{
    static int RAND_SEED_FLAG;
    if (RAND_SEED_FLAG == 0)
    {
        srand((unsigned int)time(NULL));
        RAND_SEED_FLAG = 1;
    }
    return minvalue + (int)(rand() * (maxvalue - minvalue + 1.0) / (1.0 + RAND_MAX));
}

int main(int argc, char **argv)
{
    const int max_message_length = 100;
    const int server_rank = 0;
    MPI_Status status;
    int my_rank;
    int num_proc;
    int source;
    int destination;
    int tag = 0;
    int mpi_error_code;
    int length=0;
    mpi_error_code = MPI_Init(&argc, &argv);
    mpi_error_code = MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    mpi_error_code = MPI_Comm_size(MPI_COMM_WORLD, &num_proc);
    int localarr[num_proc + 1];
    int message[2];
    int max_val = 0;
    int max_index = 0;
    for (int i = 0; i < num_proc; i++)
    {
        /* code */
        localarr[i] = 0;
    }
    srand(my_rank*time(NULL));
    if (my_rank != server_rank)
    {
        /* code */
        int index = rand() % num_proc + 1;
        message[0] = index;
        destination = server_rank;
        mpi_error_code = MPI_Send(message, strlen(message) + 1, MPI_CHAR, destination, tag, MPI_COMM_WORLD);
        //mpi_error_code = MPI_Send(&index,1, MPI_CHAR, destination, tag, MPI_COMM_WORLD);
        printf("Rank %d vote: to %d\n", my_rank, index);
    }
    else
    {
        //int index;

        for (source = 0; source < num_proc; source++)
        {
            /* code */
            if (source != server_rank)
            {
                mpi_error_code = MPI_Recv(message, max_message_length + 1, MPI_CHAR, source, tag, MPI_COMM_WORLD, &status);
                //mpi_error_code = MPI_Recv(index, 1, MPI_CHAR, source, tag, MPI_COMM_WORLD, &status);
                localarr[message[0]] += 1;
                //fprintf(stderr, "%d\n", message[0]);
            }
        }
    }
    if (my_rank == server_rank)
    {
        /* code */
        for (int i = 0; i < num_proc; i++)
        {
            /* code */
            if(max_val < localarr[i]){
                max_val = localarr[i];
                max_index = i;
                printf("%d\n",max_index);
            }
        }
    }

    mpi_error_code = MPI_Bcast(&max_index,1, MPI_INTEGER, server_rank, MPI_COMM_WORLD);
    printf("%d : max index = %d\n", my_rank, max_index+1);
    mpi_error_code = MPI_Finalize();
    return 0;
}