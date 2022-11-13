#include <omp.h>
#include <stdio.h>
#include <windows.h>
#include <locale.h>

int main(int argc, char *argv[])
{
	
	
	//последовательная область
	setlocale(LC_ALL, "rus");
	int n, count = 0;
	
	
	//параллельная область
	#pragma omp parallel
	{
		
		
		//область, в которой код, который должен выполняться одним потоком за раз
		#pragma omp critical
		{
			++count;
			n=omp_get_thread_num();
			printf("Нить %d\n", n);
		}
		
		
	}
	printf("Число нитей: %d\n", count);
}
