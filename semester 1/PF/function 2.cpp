#include <stdio.h>
int num(int x);
int main()
{
	int x,c;
	printf("enter any number? \n");
	scanf("%d",&x);
	
	c=num(x);
}
int num(int x)
{
	if(x%2==0){
		printf("even");
	}else{
		printf("odd");
	}
}
