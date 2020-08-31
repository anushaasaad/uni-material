#include<stdio.h>
#include<math.h>

int fab(int n);
int main()
{
	int n,i;
	printf("enter n");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		int b=fab(i);
		printf(" %d",b);
	}
}


int fab(int n)
{
if(n==0 || n==1)
return n;
else
return fab(n-1)+fab(n-2);
}

