#include <stdio.h>
#include <stdlib.h>
int main ()
{
	FILE *fp;
	int ch=0, word=0,i;
	char a[50];
	fp=fopen("removing.dat","a+");
	if(fp==NULL){
		printf("file cannot open");
		return 0;
		
	}else{
		printf("enter anything?:");
		scanf("%s",a);
		rewind(fp);
		while(fscanf(fp,"%s",a)!=EOF){
			if(a== ' ' || a== '\n'){
				word++;
				
			}else{
				ch++;
			}
		}
	}
	printf("the no of words in a file are:%d",word);
	printf("the no of characters in a file are:%d",ch);
	
}
