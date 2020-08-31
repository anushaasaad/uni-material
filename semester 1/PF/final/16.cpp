#include<stdio.h>
#include<Stdlib.h>
int main()
{
	int n,i;
	printf("How many numbers you want to enter?");
	scanf("%d",&n);
	int *num=(int*)calloc(n,sizeof(int));

	for(i=0;i<n;i++)
	{
		printf("Enter the number:");
		scanf(" %d",&num[i]);
		if(i>0)
		{
			if(num[i-1]>num[i])
			num[i]=num[i-1];
		}
		
	}
	printf("Largest number is %d",*(num+i-1));
	
}

