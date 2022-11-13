#include <omp.h>
#include <stdio.h>
#include <windows.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int n;
	int arr[1000];
	for(int i=0; i<1000; ++i)
	{
		arr[i] = rand()%101;
	}
	int max=arr[0];
	double start_time, end_time, tick;
	start_time = omp_get_wtime();
	
	
	//����������� ������������� �������� �������
#pragma omp parallel shared(max) private(n)
	{
#pragma omp for
		for(int i=1; i<1000; ++i)
		{
			if(arr[i]>max)
			{
				max=arr[i];
			}
		}
#pragma omp critical
		{
			n=omp_get_thread_num();
			printf("���� %d, max=%d\n", n, max);
		}
	}
	
	
	end_time = omp_get_wtime();
	tick = omp_get_wtick();
	printf("����� �� ����� ������� %lf\n", end_time-start_time);
	printf("�������� ������� %lf\n", tick);
	return 0;
}
