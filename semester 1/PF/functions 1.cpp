#include <stdio.h>
int square(int x);

int main ()
{
	int x,s;
	printf("enter any number? \n");
	scanf("%d",&x);
	s=square(x);
	printf("sqaure=%d",s);
}
int square(int x)
{
	int s;
	s=x*x;
}
