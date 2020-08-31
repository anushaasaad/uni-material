#include <stdio.h>
void factorial(int n, int *f){
	int i;
	*f=1;
    for(i=1; i<=n; i++){
		*f=*f * i;
	}
	printf("factorial:%d",*f);
}
int main()
{
	int n,i,fact;
	printf("enter the no to find factorial?:");
	scanf("%d",&n);
	factorial(n,&fact);
	
}

