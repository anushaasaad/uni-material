#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
int main()
{
	char a[20],i;
	int v=0,c=0;
	printf("enter anything?:");
    scanf("%s",a);
	for(i=0; i!='\0'; i++){
		if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u'){
			v++;
		}else{
			c++;
		}
		
	}
	printf("consonant=%d\nvowel=%d\n",c,v);	
}
