#include<stdio.h>
int main()
{
	int i,a,j;
	printf("Enter the number? ");
	scanf("%d",&a);
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=i;j++)
		{
		printf("*");}
	printf("\n");
		}
	// this will be performed in the way that first the value of i will satisfy then the value of jwill be 0 each and every time when the program will be implemented means the for loop will be implemented the value of j will be incremented only in it's own loop.//
}

