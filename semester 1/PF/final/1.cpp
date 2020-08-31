#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	gets(a);
	
	int n=strlen(a),wordcount=0,i;

	for(i=0;i<n-1;i++)
	{
		if(a[i]==' ')
		{
			wordcount+=1;
			
			
		}
		
		
}
printf("haha %d",wordcount);
}

