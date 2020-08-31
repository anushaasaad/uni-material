#include <stdio.h>
#include <string.h>
#include <conio.h>
int main()
{
	char a[10];
	printf("enter word:");
	gets(a);
	int len=strlen(a);
	int i;
	for (i=0; i!='\0'; i++){
        	if(a[len-1]=='f' && a[len-2]=='e'){
			
        		strcat(a,"ves");
		}else
		 if(a[len-1]=='s' || a[len-1]=='c'){
			    strcat(a,"es");
		}
	
printf("plural form:%s",a);
	
}
}
