#include<stdio.h>
#include<string.h>
int main()
{
	int i,n;
	char a[100],temp;
	printf("Enter a string: ");
	gets(a);
	n=strlen(a);
	for(i=0;i<n+1;i++)
	{ 
	
		if(a[i]>a[i+1])
		{
			temp=a[i];
			a[i]=a[i+1];
			a[i+1]=temp;
		}
	}
	puts(a);
	
}

