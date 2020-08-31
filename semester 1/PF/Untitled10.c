#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
int main()
{
	char a[20];
	char *p;
	int i;
	printf("enter anything?:");
    scanf("%s",&a);
    p=a;
    for(p[i]='\0' ;i>=0 ; i--){
    	printf("%c",p[i]);
	}
}
