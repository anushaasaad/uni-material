#include <stdio.h>
int main ()
{
	char a[100];
	int i,n,p;
	printf("Enter your sentence\n");
	gets(a);
	printf("enter the position: ");
	scanf("%d",&p);
	printf("How many characters you want to extract from the line? ");
	scanf("%d", &n);
	for(i=p; i<p+n ;i++)
	{
	printf("%c",a[i]);
	}

}
