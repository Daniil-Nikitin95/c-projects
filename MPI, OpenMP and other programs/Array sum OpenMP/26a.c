#include <omp.h>
#include <stdio.h>
#include <windows.h>
#include <locale.h>

int main(int argc, char *argv[])
{
	
	
	//���������������� �������
	setlocale(LC_ALL, "rus");
	int n, count = 0;
	
	
	//������������ �������
	#pragma omp parallel
	{
		
		
		//�������, � ������� ���, ������� ������ ����������� ����� ������� �� ���
		#pragma omp critical
		{
			++count;
			n=omp_get_thread_num();
			printf("���� %d\n", n);
		}
		
		
	}
	printf("����� �����: %d\n", count);
}
