#include <stdio.h>
int main ()
{
	char a[20];
    int i, cnt=0;
 
    printf("Enter a string\n");
    gets(a);
    
    for(i=0; a[i]!='\0'; i++){
			cnt++;
		}
		printf("the length of %s string is=%d",a,cnt);
	}

