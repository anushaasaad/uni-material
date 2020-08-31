#include <stdio.h>
int main(){
	int n;
	printf("enter size of array=");
	scanf("%d",&n);
	int a[n],i,temp;
	int *p;
	p=&a;
	for(i=0; i<n; i++){
		printf("\nn[%d]=",i);
		scanf("%d",&a[i]);
	}
	for(i=n-1; i>=0; i--){
		printf("%d ",*(p+i));
		
		
		
	}
}
