#include <Stdio.h>
int main()
{
	int i,a[5];
	for(i=1; i<=5; i++){
		printf("\nn[%d]=",i);
		scanf("%d",&a[i]);
	}
	int min=a[0];
	int *p=a;
	for(i=1; i<=5; i++){
		if(min>*(p+i)){
			min=*(p+i);
		}
	}
	printf("%d",min);
}
