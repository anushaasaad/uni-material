#include<stdio.h>
int main()

{
	int i,j,n,k=1;
	printf("Enter: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{   if(k<10)
		printf("%d  ",k);
		else
			printf("%d ",k);
			k++;
		}
	printf("\n");
	}
	
}
