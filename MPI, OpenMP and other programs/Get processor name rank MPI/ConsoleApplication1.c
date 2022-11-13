#include <stdio.h>
#include "mpi.h"
#define NTIMES 100 //Определение константы

int main(int argc, char* argv[])
{
    /*Объявление переменных времени*/
    double time_start, time_finish;
    int rank, i;
    int len;
    /*Инициализация массива name типа char*/
    char name[20];
    /*Начать работу с MPI*/
    MPI_Init(&argc, &argv);
    /*Получить номер текущего процесса в группе всех процессов*/
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    /*Получить имя узла, на котором запущен вызвавший процесс*/
    MPI_Get_processor_name(name, &len);//В переменной len возвращается количество символов в имени, не превышающее константы MPI_MAX_PROCESSOR_NAME
    int sum = 0;
    /*Получаем время перед началом цикла*/
    time_start = MPI_Wtime();
    /*Выполнить цикл 100 раз*/
    for (i = 0; i < NTIMES; i++)
        sum += i;
    /*Получаем время после окончания цикла*/
    time_finish = MPI_Wtime();
    printf("processor %s, process %d time=%g\n", name, rank, time_finish - time_start);
    /*Заканчиваем работу с MPI*/
    MPI_Finalize();
    return 0;
}
