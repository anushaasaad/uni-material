#include<stdio.h>
#include<string.h>
int main()
{
	char a[300][300] , temp[100] ;
	int i , j , n ;
	printf("Enter how many names you want to enter ? ");
	scanf(" %d",&n);
	for( i=0 ; i<n ; i++ )
	{
			gets(a[i]);
	}
	
	for( i=0 ; i<n ; i++ )
	{
		for( j=i+1 ; j<n ; j++ )
		{
			if((strcmp(a[i],a[j]))>0)
			{
				strcpy(temp,a[i]);
				strcpy(a[i],a[j]);
				strcpy(a[j],temp);
			}
		}
	}
	for( i=0 ; i<n ; i++ )
	{
			printf("%s\n",a[i]);
	}
	
	
	
}

