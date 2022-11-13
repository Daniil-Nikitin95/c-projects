#include <stdio.h>
#include <omp.h>
 
int main(int argc, char *argv[]) 
{
	
	
	//последовательная область
	srand(time(0));
	int N=atoi(argv[1]);
	int mass[N], max, min;
	double start_time, end_time, tick;
	double omp_get_wtime(void);
	int count = 0;
	printf("Vvedite massiv iz %d elementov", N);
	
	
	//заполнение масива случайными числами
	for(int r = 0; r<N; r++)
	{
		mass[r] = rand()%99;
	//	cout << mass[r] << " ";
	}
	for(int g=1; g<11; g++)
	{
		printf("Kolichestvo nitei: \n");
		start_time = omp_get_wtime();
		max = mass[0];
	
	
		//параллельная область
		#pragma omp parallel num_threads(g) reduction(max:max)
		#pragma omp for
		for(int r = 1; r<N; r++)
		{
			if(max < mass[r]) max = mass[r];
		}
	
	
		//последовательная область
		end_time = omp_get_wtime();
		printf("Max = %d\n", max);
		printf("Vremya dlya %d nitei = %g\n", g, end_time-start_time);
		printf("Tochnost taimera = ", tick);
	}
	return 0;
}
