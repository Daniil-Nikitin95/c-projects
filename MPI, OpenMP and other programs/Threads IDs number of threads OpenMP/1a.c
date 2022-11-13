#include "omp.h"
#include <stdio.h>
#include <windows.h>

//setlocale(LC_ALL, "rus");

int main(){
	
	
	//проверка подключения OpenMP
#ifdef _OPENMP
printf("OpenMP is supported!\n");
#endif
}
