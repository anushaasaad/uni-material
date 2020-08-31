#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
void sorting(int n, int *p);
int main()
{
	int i,n;
	int a[n];
	printf("enter size of array?:");
	scanf("%d",&n);
	for(i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	sorting(n,a);
}
void sorting(int n, int *p)
{
	int i,*t,j;
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
		
		if(p[i]<p[j]){
			*t=p[i];
			p[i]=p[j];
			p[j]=*t;
		}
	}
		for(i=0; i<n; i++){
			printf("%d ",*(p+i));
}
}
}
