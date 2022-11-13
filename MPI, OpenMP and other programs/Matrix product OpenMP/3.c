#include <stdio.h>
#include <omp.h>
#include <locale.h>

int main(int argc, char *argv[]){
	
	
	//последовательная область
system("chcp 1251");
srand(time(NULL));
//Размер матриц:
int N=atoi(argv[1]);
//Индексные переменные:
int i,j,k;
double start_time, end_time, tick;
double omp_get_wtime(void);
printf("Kolichestvo elementov v stroke/stolbze %d\n", N);
//Первая матрица:
int A[N][N];
//Вторая матрица:
int B[N][N];
//Третья матрица (результат):
int C[N][N];


//Ввод элементов первой матрицы:
printf("Matrix A:\n");
for(i=0; i < N; i++){
 for(j=0; j < N; j++){
 A[i][j] = rand()%10;
}
}


for(int y=0; y<N; y++){
	for(int u=0; u<N; u++){
		//cout << A[y][u] << " ";
	}
	//cout << endl;
}
printf("\n");


//Ввод элементов второй матрицы:
printf("Matrix B:\n");
for(i=0; i < N; i++){
 for(j=0; j < N; j++){
 B[i][j] = rand()%10;
}
}


for(int y=0; y<N; y++){
	for(int u=0; u<N; u++){
		//cout << B[y][u] << " ";
	}
	//cout << endl;
}
printf("\n");


//Вычисление произведения матриц:
printf("Matrix C=AB:\n");
for(int g=1; g<11; g++)
{
start_time = omp_get_wtime();


//параллельная область
#pragma omp parallel num_threads(g) private(i, j, k)
#pragma omp for
for(i=0; i < N; i++){
 for(j=0; j < N; j++){
 C[i][j]=0;
 for(k=0; k < N; k++){
 C[i][j]+=A[i][k]*B[k][j];
 //Вывод значения элемента на экран:
}
}
 //cout << endl;
}


//последовательная область
for(int t=0; t<N; t++){
for(int p=0; p<N; p++){
//cout << C[t][p] << " ";
}
//cout << endl;
}
end_time = omp_get_wtime();
printf("Nomer niti: \n", g);
printf("Vremya dlya %d nitei = %g\n", g, end_time-start_time);
printf("Tochnost taimera = ", tick);
printf("\n");
}
return 0;
}

