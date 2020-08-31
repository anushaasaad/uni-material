#include<stdio.h>
int main()
{
	int n,num=0, num2=0,count=0,o;
	printf("Enter the number: ");
	scanf("%d",&n);
	printf("Enter the occurence number: ");
	scanf("%d",&o);
	while(n!=0)
	{
		num=n%10;
		n=n/10;
		if(num==o)
		{
			count++;
		}
		if(num==num2)
		{
			count++;
		}
		num2=num;
		
	}
	printf("\nOccurence is %d",count);
}
