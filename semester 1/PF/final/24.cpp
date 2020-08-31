#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int i,n=10,j=10;
	int *p=(int *)calloc(n,sizeof(int));
	int a[n];
	for(i=1; i<=n; i++){
		printf("%d ",i);
	}
	printf("\n-------------------\n");
	for(i=1; i<=n; i++){
		if(i%2!=0){
	    	printf("%d ",--j);
	    	j--;
	    	
		}else{
			printf("%d ",i);
		}
	}
	
}
