#include <omp.h>
#include <stdio.h>
#include <windows.h>
#include <locale.h>

//setlocale(LC_ALL, "rus");

int main(int argc, char *argv[])
{
setlocale(LC_ALL, "rus");
printf("���������������� ������� 1\n");
#pragma omp parallel
{
printf("������������ �������\n");
}
printf("���������������� ������� 2\n");
}
