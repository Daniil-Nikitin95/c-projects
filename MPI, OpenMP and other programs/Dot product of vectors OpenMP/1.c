#include <omp.h>
#include <stdio.h>
#include <windows.h>
#include <locale.h>

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int arr_x[100000];
	int arr_y[100000];
	int res=0;
	double start_time, end_time, tick;
	start_time = omp_get_wtime();
	
	
	//вычисление произведения двух массивов
	#pragma omp parallel reduction (+: res) num_threads(12)
	{
		#pragma omp for
		for(int i=0; i<100000; ++i)
		{
			arr_x[i] = rand()%11-10;
			arr_y[i] = rand()%11-10;
//			printf("x = %d, y = %d\n\n", arr_x[i], arr_y[i]);
		}
		#pragma omp for
		for(int i=0; i<100000; ++i)
		{
			res+=arr_x[i]*arr_y[i];
		}
	}
	
	
	end_time = omp_get_wtime();
	tick = omp_get_wtick();
	printf("Результат скалярного произведения массивов = %d\n", res);
	printf("Время на замер времени %lf\n", end_time-start_time);
	printf("Точность таймера %lf\n", tick);
	return 0;
}
