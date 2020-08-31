#include<stdio.h>
#include<string.h>
int main()
{
	char a[100],b[20];
	gets(a);
	printf("Enter the Word:");
	gets(b);
	int n=strlen(a),n1=strlen(b),wordcount=1,i,j,count=0;

	for(i=0;i<n-1;i++)
	{
		if(a[i]=' ')
		{
			wordcount+=1;
			i++;
			continue;
			
		}
		
		for(j=0;j<n1-1;j++)
		{
			if(a[i+j]=b[j])
			{
				count+=1;
			}
			if((count+1)==n1)
			{
				printf(" position is %d",wordcount);
			}
		}
		
	}
}

