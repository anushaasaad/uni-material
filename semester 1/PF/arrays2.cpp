#include <stdio.h>
int main ()
{
	int i,n,c,j,a[100];
	printf("enter no you want to enter:");
	scanf("%d",&n);
	
	printf("enter nos: \t");
	for(i=0; i<n; i++){
	scanf("%d",&a[i]);		
	}
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(a[i]<a[j]){
			c=a[i];
			a[i]=a[j];
			a[j]=c;	
			}
		}
	}
	for(i=0; i<n; i++){
	printf("%d\t",a[i]);	
}
}
