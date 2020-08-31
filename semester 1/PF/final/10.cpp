//fabonaaci series
#include<stdio.h>
#include<math.h>

int fab(int n , int n1,int c);
int main()
{
	int n=1,n1=1,c=1;
	printf(" %d",n);
	fab(n,n1,c);
}


int fab(int n , int n1,int c)
{
	printf(" %d",n1);
	int temp=n1;
	n1=n+n1;
	n=temp;
	c++;
	
	if(c>24)
	return 0;
	else 
	{
	
	return fab(n,n1,c);}
	
	
}

