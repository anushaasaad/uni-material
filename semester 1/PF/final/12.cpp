#include<stdio.h>
int main()
{
	int j,k,i,n;
	printf("Enter the amount of numbers you want to enter : ");
	scanf("%d",&n);
	int a[n],b[n],c[2*n];
	printf("Enter the numbers:");
	for(j=0;j<n;j++)
	{
		scanf("%d",&a[j]);
			
	}
	
	for(j=0;j<n;j++)
	{
		scanf("%d",&b[j]);
			
	}
	for(i=0,j=0,k=0;i<2*n;i++)
	{
		if(i%2==0)
		{
			c[i]=b[j];
			j++;
		}
		else
		{
		c[i]=a[k];
			k++;}
		
	}
	for(j=0;j<2*n;j++)
	{
		printf(" %d ",c[j]);
			
	}
	 
}

