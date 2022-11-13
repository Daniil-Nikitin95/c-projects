#include <stdio.h>
#include "mpi.h"

int main(int argc, char** argv)
{
	srand(time(NULL));
	//Индексные переменные:
	int i, j, k;
	int size, rank;
	double start_time, finish_time;
	MPI_Init(&argc, &argv);
	MPI_Status status;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	//инициализация матрицы каждым процессом:
	printf("Kolichestvo elementov v stroke/stolbze 500\n");
	//Первая матрица:
	int A[500][500];
	//Вторая матрица:
	int B[500][500];
	//Третья матрица (результат):
	int C[500][500];


	//Ввод элементов первой матрицы:
	printf("Matrix A:\n");
	for (i = 0; i < 500; i++) {
		for (j = 0; j < 500; j++) {
			A[i][j] = rand() % 10;
		}
	}
	for (int y = 0; y < 500; y++) {
		for (int u = 0; u < 500; u++) {
			//cout << A[y][u] << " ";
		}
		//cout << endl;
	}
	printf("\n");


	//Ввод элементов второй матрицы:
	printf("Matrix B:\n");
	for (i = 0; i < 500; i++) {
		for (j = 0; j < 500; j++) {
			B[i][j] = rand() % 10;
		}
	}
	for (int y = 0; y < 500; y++) {
		for (int u = 0; u < 500; u++) {
			//cout << B[y][u] << " ";
		}
		//cout << endl;
	}
	printf("\n");
	MPI_Barrier(MPI_COMM_WORLD); //барьерная синхронизация процессов
	start_time = MPI_Wtime();//начало замера времени для каждого процесса


	//перемножение матриц:
	printf("Matrix C=AB:\n");
	for (i = 0; i < 500; i++) {
		for (j = 0; j < 500; j++) {
			C[i][j] = 0;
			for (k = 0; k < 500; k++) {
				C[i][j] += A[i][k] * B[k][j];
				//Вывод значения элемента на экран:
			}
		}
		//cout << endl;
	}
	for (int t = 0; t < 500; t++) {
		for (int p = 0; p < 500; p++) {
			//cout << C[t][p] << " ";
		}
		//cout << endl;
	}
	finish_time = MPI_Wtime();//конец замера времени
	printf("Vremya vipolnenia peremnojenia matriz na kajdom processe= %g\n", finish_time - start_time);//вывод время выполнения перемножения матриц на каждом процессе
	MPI_Finalize();
}