#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
int countlength(char* p){
	int cnt=0;
	for( ; *p!='\0';*p++){
		cnt++;
	}
	return cnt;
	
}
int main()
{
	char a[20];
	int len;
	printf("enter anything?:");
    scanf("%s",a);
    len=countlength(a);
    printf("length=%d",len);
}
