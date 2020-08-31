#include<stdio.h>
#include<string.h>
int main()
{
	char a[60];
	int len,i,j;
	printf("enter a string");
	scanf("%s", &a);
	len=strlen(a);
	for(i=0;i<len;i++)
	{
		if (a[i] =='a' || a[i] =='A' || a[i] =='e' || a[i] =='E' || a[i] =='i' || a[i] =='I' || a[i] =='o' || a[i]=='O' || a[i] =='u' || a[i] =='U'){
			for(j=i; j<len; j++){
				a[j]=a[j+1];

			}
			len--;
		}
	}
	printf("\nstring after deleting vowels=%s",a);
}
