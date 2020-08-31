#include <stdio.h>
int main(){
	int i, even=0, odd=0,a[10];
	for(i=1; i<=10; i++){
		printf("\nn[%d]=",i);
		scanf("%d",&a[i]);
	}
	int *p=a;
	for(i=1; i<=10; i++){
		if(i%2==0){
			even+=a[i];
		}else{
			odd+=a[i];
		}
	}
	printf("even=%d\n",even);
	printf("odd=%d",odd);
	
}
