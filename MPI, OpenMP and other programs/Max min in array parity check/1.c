#include <stdio.h>
#include <windows.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int arr[1000];
	
	
	//Заполняем массив тысечей случайных чисел от 0 до 100
	for(int i=0; i<1000; ++i)
	{
		arr[i] = rand()%101;
	}
	
	
	int max = arr[0];
	
	
	//определяем максимальное число из этих 100 чисел
	for(int i=1; i<1000; ++i)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	
	
	int min = arr[0];
	
	
	//определяем минимальное число из этих 100 чисел
	for(int i=1; i<1000; ++i)
	{
		if(arr[i]<min)
		{
			min=arr[i];
		}
	}
	
	
	//определяем, максимальное и минамальное числа четные или нет
	if(max%2==0)
	{
		printf("max=%d - четное число\n\n", max);
	}
	else
	{
		printf("max=%d - нечетное число\n\n", max);
	}
	if(max%2==0)
	{
		printf("min=%d - четное число\n\n", min);
	}
	else
	{
		printf("max=%d - нечетное число\n\n", min);
	}
	
	
	return 0;
}
