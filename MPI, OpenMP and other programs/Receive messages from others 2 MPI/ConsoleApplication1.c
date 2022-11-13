#include <stdio.h>
#include "mpi.h"

int main(int argc, char* argv[]) {
	MPI_Init(&argc, &argv);
	int rank, n, i, message;
	MPI_Status status;
	MPI_Comm_size(MPI_COMM_WORLD, &n);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if (rank == 0)
	{
		printf("Hello from process %d\n", rank);
		for (i = 1; i < n; i++) {


			//получение сообщений от каждого процесса, кроме нулевого
			MPI_Recv(&message, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
			printf("Hello from process %d\n", message);
		}
	}
	else MPI_Send(&rank, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
	MPI_Finalize();
	return 0;
}