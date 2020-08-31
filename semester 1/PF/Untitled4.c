#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int n1,n2,result;
	printf("1,add\n2.subtract\n3.multiply\n4.divide\n");
	printf("num=");
	scanf("%d%d",&n1,&n2);
	scanf("%d",&result);
	switch(result)
	{
		case 1:
			result=n1+n2;
			break;
		
		case 2:
			result=n1-n2;
			break;
		
		case 3:
			result=n1*n2;
			break;
			
		case 4:
			result=n1/n2;
			break;
			
		default:
			printf("not given");
	}
	printf("result=%d",result);
}
