#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i;
	char a[100];
	gets(a);
	char*my=(char*)calloc(strlen(a),sizeof(char));
	for(i=0;i<(strlen(a));i++)
	{
		my[i]=a[i];
		printf("%c",my[i]);
		
	}
	free(my);
	my=&a;
	printf("%c",my[0]);
}

