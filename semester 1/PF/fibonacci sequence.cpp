#include <stdio.h>
int rec(int x, int n,int x1,int x2);
int main ()
{
	int x1, x2, x;
	printf("x1 x2=");
	scanf("%d %d ",&x1,&x2);
	int n=0;
	rec(x,n,x1,x2);
}
int rec(int x, int n,int x1,int x2)
{
	if(n<=25){
	x=x1+x2;
	printf("\t %d",x);
	x1=x2;
	x2=x;
	n++;
	rec(x,n,x1,x2);
	}else
	{
		return x;
	}
}
