#include <stdio.h>
#include <omp.h>
#include <locale.h>

int main(int argc, char *argv[]){
	
	
	//���������������� �������
system("chcp 1251");
srand(time(NULL));
//������ ������:
int N=atoi(argv[1]);
//��������� ����������:
int i,j,k;
double start_time, end_time, tick;
double omp_get_wtime(void);
printf("Kolichestvo elementov v stroke/stolbze %d\n", N);
//������ �������:
int A[N][N];
//������ �������:
int B[N][N];
//������ ������� (���������):
int C[N][N];


//���� ��������� ������ �������:
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


//���� ��������� ������ �������:
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


//���������� ������������ ������:
printf("Matrix C=AB:\n");
for(int g=1; g<11; g++)
{
start_time = omp_get_wtime();


//������������ �������
#pragma omp parallel num_threads(g) private(i, j, k)
#pragma omp for
for(i=0; i < N; i++){
 for(j=0; j < N; j++){
 C[i][j]=0;
 for(k=0; k < N; k++){
 C[i][j]+=A[i][k]*B[k][j];
 //����� �������� �������� �� �����:
}
}
 //cout << endl;
}


//���������������� �������
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

