#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
int main()
{
	char a[50];
	char *p;
	int i;
	printf("enter anything?:");
    scanf("%s",a);
    p=a;
    for(i=0; p[i]!='\0'; i++){
    	if(p[i]>='a' && p[i]<='z'){
    		a[i]-=32;
		}
	}
	printf("In Upper Case is: "); 
    puts(p);
}
