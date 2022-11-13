#include <omp.h>
#include <stdio.h>
#include <windows.h>
#include <locale.h>

//setlocale(LC_ALL, "rus");

int main(int argc, char *argv[])
{
setlocale(LC_ALL, "rus");
int count, num;
printf("Последовательная область 1\n");
#pragma omp parallel
{
count=omp_get_num_threads();//получить количетво параллельных нитей
num=omp_get_thread_num();	//получить номер каждой нити
if (num == 0) printf("Всего нитей: %d\n", count);
else printf("Нить номер %d\n", num);
}
printf("Последовательная область 2\n");
}

