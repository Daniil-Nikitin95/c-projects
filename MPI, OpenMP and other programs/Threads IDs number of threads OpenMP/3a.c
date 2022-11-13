#include <omp.h>
#include <stdio.h>
#include <windows.h>
#include <locale.h>

//setlocale(LC_ALL, "rus");

int main(int argc, char *argv[])
{
setlocale(LC_ALL, "rus");
printf("Последовательная область 1\n");
#pragma omp parallel
{
printf("Параллельная область\n");
}
printf("Последовательная область 2\n");
}
