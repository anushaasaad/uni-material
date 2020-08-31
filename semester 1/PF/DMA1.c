#include <stdio.h>
#include <stdlib.h>
int main()
{
	int max, max2 ,i,n,sum=0;
	int *p;
	printf("enter how many no you want to enter :");
	scanf("%d",&n);
	int a[n];
	p=a;
	max=0;
	p=(int*)calloc(n,sizeof(int));
	
	for (i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	for (i=0; i<n; i++){
		sum= *(p+i)+ sum;
	}
	printf("sum=%d\n",sum);
	
	for(i=0; i<n; i++){
		if(a[i]>max){
			max2=max;
			max=a[i];
		}else if(a[i]>max2 && a[i]<max){
			max2=a[i];
		}
	}
	float avg;
	avg= sum/ n;
	printf("avg=%d\n",avg);
	printf("max=%d\n",max);
	printf("max2=%d\n",max2);
	
	
	
}
