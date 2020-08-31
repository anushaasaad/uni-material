#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
int main()
{
	char a[20];
	char *p;
	int v=0,c=0,i;
	printf("enter anything?:");
    scanf("%s",a);
    p=a;
	for( ; *p!='\0'; *p++){
		if(*p=='a' || *p=='e' || *p=='i' || *p=='o' || *p=='u'){
			v++;
		}else{
			c++;
		}
		
		
	}
	printf("consonant=%d\nvowel=%d\n",c,v);	
}
