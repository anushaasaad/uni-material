#include <stdio.h>
int main()
{
	int n,i,a[n];
	int max,min,max_position,min_position,t;
	printf("enter the size of array:");
	scanf("%d",&n);
	for(i=0; i<n; i++){
		printf("enter number:");
		scanf("%d",&a[i]);
	}
	min=-999;
	max=999;
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
	printf("before swapping");
	for(i=0; i<n; i++){
		printf("%d",a[i]);
	}
	t=a[max_position];
	a[max_position]=a[min_position];
	a[min_position]=t;
	
	printf("after swapping");
	for(i=0; i<n; i++){
		printf("%d",a[i]);
	}
		
}
