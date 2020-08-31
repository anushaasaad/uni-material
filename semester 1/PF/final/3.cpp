#include<stdio.h>
int main()
{
	int i;
	char s[20];
	scanf("%s",s);
		for(i=0;i<20;i++)
		{
			if(s[i]=='/o')
			printf(".");
			else printf("%c",s[i]);
		}
}
