#include <stdio.h>
#include "mpi.h"
#define n 1000

void smod5(void* a, void* b, int* l, MPI_Datatype* type) {
	int i;
	int max = ((int*)a)[0];
	for (i = 0; i < *l; i++) {
		if (max < ((int*)a)[i]) max = ((int*)a)[i];          // ((int*)b)[i] = (((int*)a)[i] + ((int*)b)[i])%5;
	}
	((int*)b)[0] = max;
}
int main(int argc, char** argv)
{
	int rank, size, i;
	int a[1];
	int b[1];
	MPI_Init(&argc, &argv);
	MPI_Op op;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	a[0] = rank;
	MPI_Op_create(&smod5, 1, &op); //Создается определяемый пользователем дескриптор комбинированной функции


	//MPI_Reduce сводит значения всех процессов к одному значению
	MPI_Reduce(a, b, 1, MPI_INT, op, 0, MPI_COMM_WORLD);
	if (rank == 0)
	{
		printf("MAX(op)= %d\n", b[0]);
	}
	MPI_Reduce(a, b, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
	if (rank == 0)
	{
		printf("MAX(MPI_MAX)= %d\n", b[0]);
	}


	MPI_Op_free(&op);
	MPI_Finalize();
}