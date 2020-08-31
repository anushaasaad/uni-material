#include <stdio.h>
int main ()
{
	int a, b;
	int *p , *c;
	printf("enter the nos a , b==");
	scanf("%d %d",&a,&b);
	p=&a;
	c=&b;
	if(*p>*c){
		printf("%d",*p);
	}else{
		printf("%d",*c);
	}
}
