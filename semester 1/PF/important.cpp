#include <stdio.h>
int locatelargest(int a[5]);
int main ()
{
	int i,a[5];
	for(i=0;i<5;i++){
		printf("enter number[%d]",i);
		scanf("%d",&a[i]);
	}
	printf("The original numbers list\n");
	for(i=0;i<5;i++){
		printf("%d ",a[i]);
	}
	locatelargest(a);
}
int locatelargest(int a[5])
{
	int max,position,i;
	max=a[0];
	for(i=0; i<5; i++){
		if(max<a[i]){
			max=a[i];
			position=i;
		}
	}
	printf("\nthe largest number is at position=%d",position);
}
