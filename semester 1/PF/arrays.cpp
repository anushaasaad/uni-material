#include <stdio.h>
int main()
{
	int n,sum=0,a,i[100];
	float avg;
	printf("enter number you want to add? \n");
	scanf("%d",&n);
	
	printf("enter %d numbers?",n);
	
	for(a=0;a<n;a++){
		scanf("%d",&i[a]);
		
		sum+=i[a];
	}
	avg=sum/n;
	printf("average=%.3f",avg);
}
