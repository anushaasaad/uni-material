#include <stdio.h>
int check(int x);
int main()
{
	int x,result;
	printf("enter number? \n");
	scanf("%d",&x);
	
	result=check(x);
	
	if (result==1){
		printf("prime number");
	}else{
		printf("not a prime number");
	}
}
int check(int x)
{
	int a;
	for(a=x-1; a<=1; a--){
		if(x%a==0){
			return 0;
		}else{
			return 1;
		}
	}
}
