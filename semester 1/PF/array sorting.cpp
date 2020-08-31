#include <stdio.h>
void seg(int n,int a[10]);
void print(int n, int a[10]);
int main()
{
	int n,i;
	printf("enter array size:");
	scanf("%d",&n);
	int a[n];
	for (i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	seg(n,a);
	print(n,a);
}
void seg(int n,int a[ ]){
	int count=0,i;
	for(i=0; i<n; i++){
		if(a[i]==0){
			count++;
		}
	for(i=0; i<count; i++){
			a[i] = 0;
		}
	for(i=count; i<n; i++){
			a[i] = 1;
		}
	}
	
}
void print(int n, int a[ ])
{
	int i;
	for(i=0; i<n; i++){
		printf("%d",a[i]);
	}
}	
	
	
	
