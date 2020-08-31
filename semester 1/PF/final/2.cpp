#include<stdio.h>
int main()
{
int arr[]={10,20,36,72,45,36};
int *j,*k;
k=(arr+4);
j=&arr[4];
if(j==k)
{
	printf("hahaha");
}
else printf("Loser!");
}

