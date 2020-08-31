#include <stdio.h>
void transpose(int i, int j, int a[i][j])
{
    a[i][j]=a[j][i];
	return(a);
}
int main()
{
	int n,i,j;
	printf("enter size of array?:");
	scanf("%d",&n);
	int a[n][n];
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("before transposing:\n");
	for(i=0; i<n; i++){
		printf("\n");
		for(j=0; j<n; j++){
			printf("%d",a[i][j]);
		}
	}
	transpose(i,j,a);
	printf("\nafter transposing:\n");
	for(j=0; j<n; j++){
		printf("\n");
		for(i=0; i<n; i++){
			printf("%d",a[i][j]);
		}
	}
}
