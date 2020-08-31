#include<stdio.h>
int main()
{
	int i,j,k;
	for(i=0;i<=10;i++){
		for(j=11-i;j>0;j--){
			printf("o ");
		}
		for(k=0;k<=i;k++){
			printf(". ");
		}
		printf("\n");		
	}

	for(i=1;i<=10;i++){
	for(k=0;k<=i;k++){
			printf("o ");
		}
		for(j=11-i;j>0;j--)
		{
			printf(". ");
		}
		printf("\n");		
	}

   }

