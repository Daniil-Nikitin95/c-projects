#include <stdio.h>
#include <windows.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int arr[1000];
	
	
	//��������� ������ ������� ��������� ����� �� 0 �� 100
	for(int i=0; i<1000; ++i)
	{
		arr[i] = rand()%101;
	}
	
	
	int max = arr[0];
	
	
	//���������� ������������ ����� �� ���� 100 �����
	for(int i=1; i<1000; ++i)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	
	
	int min = arr[0];
	
	
	//���������� ����������� ����� �� ���� 100 �����
	for(int i=1; i<1000; ++i)
	{
		if(arr[i]<min)
		{
			min=arr[i];
		}
	}
	
	
	//����������, ������������ � ����������� ����� ������ ��� ���
	if(max%2==0)
	{
		printf("max=%d - ������ �����\n\n", max);
	}
	else
	{
		printf("max=%d - �������� �����\n\n", max);
	}
	if(max%2==0)
	{
		printf("min=%d - ������ �����\n\n", min);
	}
	else
	{
		printf("max=%d - �������� �����\n\n", min);
	}
	
	
	return 0;
}
