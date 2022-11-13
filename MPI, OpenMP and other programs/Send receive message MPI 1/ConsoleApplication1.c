#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv)
{
	int rank, size, ibuf;
	MPI_Status status;
	float rbuf;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	ibuf = rank;
	rbuf = 1.0 * rank;
	if (rank == 1) MPI_Send(&ibuf, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
	if (rank == 2) MPI_Send(&rbuf, 1, MPI_FLOAT, 0, 2, MPI_COMM_WORLD);
	if (rank == 0) {
		MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);


		//получение сообщений
		if (status.MPI_TAG == 1) {
			MPI_Recv(&ibuf, 1, MPI_INT, 1, 1, MPI_COMM_WORLD, &status);
			MPI_Recv(&rbuf, 1, MPI_FLOAT, 2, 2, MPI_COMM_WORLD, &status);
			printf("Tag 0 recv %d from tag 1, %f from tag 2\n", ibuf, rbuf);
		}
		else if (status.MPI_TAG == 2) {
			MPI_Recv(&rbuf, 1, MPI_FLOAT, 2, 2, MPI_COMM_WORLD, &status);
			MPI_Recv(&ibuf, 1, MPI_INT, 1, 1, MPI_COMM_WORLD, &status);
			printf("Tag 0 recv %d from tag 1, %f from tag 1\n", ibuf, rbuf);
		}
	}
	MPI_Finalize();
}