//Write a single function to calculate the square, cube and square root of its floating
//point argument and make those results available to the calling program./
#include <stdio.h>
#include <stdlib.h>
void result(int *p);
int main(){
	int a,cube,square;
	float root;
	int *p;
	printf("a=");
	scanf("%d",&a);
	p=&a;
	cube= (*p) * (*p) * (*p);
	printf("cube=%d\n",cube);
	square= (*p) * (*p);
	printf("square=%d\n",square);
    root= sqrt(*p);
	printf("root=%.2f",root);
}
