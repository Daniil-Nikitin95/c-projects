#include <stdio.h>
#include "mpi.h"

int main(int argc, char* argv[])
{
    srand(time(0));
    int rank, size, sum=0;
    int mas1[20], mas2[20], sums[5];
    MPI_Init(&argc, &argv);
    MPI_Status status;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    double start = MPI_Wtime();


    //получение сообщений от всех процессов, кроме рутового
    if (rank == 0)
    {
        for (int i = 1; i < size; ++i)
        {
            if (i == 1)
            {
                MPI_Recv(&sums[0], 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 2)
            {
                MPI_Recv(&sums[1], 1, MPI_INT, 2, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 3)
            {
                MPI_Recv(&sums[2], 1, MPI_INT, 3, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 4)
            {
                MPI_Recv(&sums[3], 1, MPI_INT, 4, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 5)
            {
                MPI_Recv(&sums[4], 1, MPI_INT, 5, 0, MPI_COMM_WORLD, &status);
            }
        }
        for (int i = 0; i < 5; ++i)
        {
            sum += sums[i];
        }
        double end = MPI_Wtime();
        printf("Sum= %d\n", sum);
        printf("Program execution time = %g", end - start);
    }


    //отправка сообщений рутовому процессу
    if (rank == 1)
    {
        for (int i = 0; i < 20; ++i)
        {
            mas1[i] = rand() % 101;
            mas2[i] = rand() % 101;
            sums[0] += mas1[i] * mas2[i];
        }
        MPI_Send(&sums[0], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 2)
    {
        for (int i = 0; i < 20; ++i)
        {
            mas1[i] = rand() % 101;
            mas2[i] = rand() % 101;
            sums[1] += mas1[i] * mas2[i];
        }
        MPI_Send(&sums[1], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 3)
    {
        for (int i = 0; i < 20; ++i)
        {
            mas1[i] = rand() % 101;
            mas2[i] = rand() % 101;
            sums[2] += mas1[i] * mas2[i];
        }
        MPI_Send(&sums[2], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 4)
    {
        for (int i = 0; i < 20; ++i)
        {
            mas1[i] = rand() % 101;
            mas2[i] = rand() % 101;
            sums[3] += mas1[i] * mas2[i];
        }
        MPI_Send(&sums[3], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 5)
    {
        for (int i = 0; i < 20; ++i)
        {
            mas1[i] = rand() % 101;
            mas2[i] = rand() % 101;
            sums[4] += mas1[i] * mas2[i];
        }
        MPI_Send(&sums[4], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }


    MPI_Finalize();
    return 0;
}
