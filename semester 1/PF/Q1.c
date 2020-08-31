#include <stdio.h>
int main ()
{
	int n,i;
	int max,min,max_position,min_position,t;

	printf("enter the size of array:");
	scanf("%d",&n);
	int a[n];
	min=100;
	max=-100;
	for(i=0; i<n; i++){
		printf("enter number:");
		scanf("%d", &a[i]);
	}
	printf("before swapping\n");
	for(i=0; i<n; i++){
		printf("%d ",a[i]);
	}
	
	for(i=0; i<n; i++){
		if(a[i]>max){
			max=a[i];
			max_position=i;
		}
		if(a[i]<min){
			min=a[i];
			min_position=i;
		}
	}

	t=a[max_position];
	a[max_position]=a[min_position];
	a[min_position]=t;
	
	printf("\nafter swapping\n");
	for(i=0; i<n; i++){
		printf("%d ",a[i]);
	}
		
}
