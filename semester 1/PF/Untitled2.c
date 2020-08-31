#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
	int i,j,r=3,c=7;
	int a[r][c];
	for(i=1; i<=r;i++){
			printf("ENTER RECORD OF MONKEY %d:",i);
		for(j=1; j<=c; j++){
			scanf("%d",&a[i][j]);
		}
	}
	monkey(r,c,a);
}
int monkey (int r, int c, int a[r][c])
{
	int i,j,max=0,min=999;
	float avg;
	for(i=1; i<=r; i++){
		printf("\n");
		for(j=1; j<=c; j++){
			printf(" %d ",a[i][j]);
		}
	}
	for(i=1; i<=r; i++){
		for(j=1; j<=c; j++){
			if(a[i][j]>max){
				max=a[i][j];
			}
			if(a[i][j]<min){
				min=a[i][j];
			}
		}
	}
	printf("max=%d\tmin=%d",max,min);
	printf("average per day:");
	int sum=0;
	for(j=0; j<c; j++){
		for(i=0; i<r; i++){
			sum=sum+a[i][j];
		}
		avg=sum/3;
		printf("\naverage[%d]=%f",j,avg);
}

}
