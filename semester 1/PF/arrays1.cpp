#include <stdio.h>
int main ()
{
	int i,n,a[100];
	printf("enter no you want to enter:");
	scanf("%d",&n);
	
	printf("enter nos: \t");
	for(i=0; i<n; i++){
	scanf("%d",&a[i]);		
	}
	printf("reverse order");
	
	for(i=n-1; i>=0; i--){
		printf("%d \t",a[i]);
	}
}
