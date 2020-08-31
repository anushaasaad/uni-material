#include <stdio.h>
void sumnum(int *s, int n, int *c);
int main ()
{
	int n;
	printf("enter size of array=");
	scanf("%d",&n);
	int a[n],i,sum=0;
	int *p;
	for(i=0; i<n; i++){
		printf("\nn[%d]=",i);
		scanf("%d",&a[i]);
	}
	p=&a;
	sumnum(p,n,&sum);
}
	
void sumnum(int *s, int n, int *c){

int i;
	for (i=0; i<n; i++){
	
		*c=*c + *(s+i);
	}
	printf("sum=%d",*c);
	
	
}

