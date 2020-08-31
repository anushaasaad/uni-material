#include <stdio.h>
int main()
{
	int i, count=1;
	printf("enter number?");
	scanf("%d",&i);
	
	while(i<=1){
		if(i%2 != 0){
			i=i*3;
			i++;
			printf("%d \n",&i);
			count++;
			
		}else 
		i=i/2;
		printf("%d \n",&i);
		count++;
	}
	printf("final number=%d \t count=%d",i,count);
	
}
