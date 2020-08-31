#include <stdio.h>
int main()
{
	int n,i;
	int a[n];
	printf("enter size of array:");
	scanf("%d",&n);
	
	printf("enter nos:");
	for(i=0; i<n; i++){
		scanf("%d\n",&a[i]);	
	}
	for(i=0; i<n; i++){
		printf("%d\t",a[i]);
	}
	printf("\nREVERSE ORDER\n");
	for(i=n-1; i>=0; i--)
	{
		printf("%d\t",a[i]);
	}
}
