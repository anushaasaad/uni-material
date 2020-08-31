#include <stdio.h>
int main()
{
	int a[50][50],i,j,r,c;
	printf("enter rows and coloumns:");
	scanf("%d%d",&r,&c);
	
	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			printf("elememts[%d][%d]:",i,j);
			scanf("%d",&a[i][j]);
			
		}
	}
	printf("matrix\n");
	for(i=0; i<r; i++){
		printf("\n");
		for(j=0; j<c; j++){
			printf("%d \t",a[i][j]);
		}
	}
	printf("\n transpose \n");
		for(j=0; j<c; j++){
		printf("\n");
		for(i=0; i<r; i++){
			printf("%d \t",a[i][j]);
		}
	}
	
}
