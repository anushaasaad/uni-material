#include<stdio.h>
int main()
{
	int A[50],n,i;
	int B[50];
	printf("Enter the first two numbers: ");
	scanf("%d %d",&A[0],&A[1]);
	printf("Enter the value of EX-N: ");
	scanf("%d",&n);
	B[0]=A[1];
	for(i=0;i<n;i++)
	{
		B[i+1]=A[i]+A[i+1];
		A[i+2]=B[i+1];
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
		
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",B[i]);
		
	}
}
