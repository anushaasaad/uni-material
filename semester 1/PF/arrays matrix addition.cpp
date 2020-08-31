#include <stdio.h>
int upperhalf(int n);
int main ()
{
	int n;
	upperhalf(n);
}
int upperhalf(int n)
{
		int a[50][50],b[50][50],c[50][50],i,j;
	printf("enter no you want to enter:");
	scanf("%d",&n);
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("element - [%d],[%d] : ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nmatrix\n");
	for(i=0; i<n; i++){
		printf("\n");
		for(j=0; j<n; j++){
			printf("%d",a[i][j]);
		}
	}
	printf("\n \n");
	printf("\nupper half of a matrix");
	  for(i=0; i<n; i++){
    	printf("\n");
    	for(j=0; j<n; j++){
    		if(i>j){
    			printf(" ");
			}else{
				printf("%d",a[i][j]);
			}
		}
	}
}
