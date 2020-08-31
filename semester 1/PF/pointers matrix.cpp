#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void printmatrix(int n, int a[][n], int b[][n]){
	int i,j;
	system("cls");
	printf("first matrix\n");
	for(i=0; i<n; i++){
		printf("\n");
		for(j=0; j<n; j++){
		printf("%d ", *(*(a + i) + j));
		}
	}
	printf("\nsecond matrix\n");
	for(i=0; i<n; i++){
		printf("\n");
		for(j=0; j<n; j++){
		printf("%d ", *(*(b + i) + j));
		}
	}
}
void addition(int n, int a[][n], int b[][n]){
	int i,j;
	printf("\naddition of matrix\n");
	int c[5][5];
	for(i=0; i<n; i++){
		printf("\n");
		for(j=0; j<n; j++){
			*(*(c+i)+j)=*(*(a+i)+j)+ *(*(b+i)+j);
		printf("%d ", *(*(c + i)+j));
		}
	}
}
int main()
{
	int n,i,j;
	int a[5][5],b[5][5];
	
	printf("enter the size of matrix?:");
	scanf("%d",&n);

	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%d",(*(a+i)+j));
		}
	}
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%d",(*(b+i)+j));
		}
	}
	printmatrix(n, &a, &b);
	addition(n,&a,&b);
	
}


