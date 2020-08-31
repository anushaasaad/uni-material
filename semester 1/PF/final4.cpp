#include <stdio.h>
#include <stdlib.h>
void even (int n, int *p)
{
	int i;
	for(i=1; i<=n; i++){
		if(i%2==0){
			printf("%d ",p[i]);
		}
	}
}
int main(){
	int n,i;
	printf("enter size of array?:");
	scanf("%d",&n);
	int a[n];
	for(i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	even(n,a);
}
