#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
int main ()
{
	FILE *fp;
	int word,i,j;
	char a[50],ch='y';
	fp=fopen("sorting.txt","a+");
	if(fp==NULL){
		printf("file cannot open");
		return 0;
	}
	while(ch=='y'){
	printf("enter anything ?:");
	gets(a);
	fprintf(fp,"%s",a);
	fflush(stdin);
	getche();
}
    rewind(fp);
    while(fscanf(fp,"%s",a)!=EOF){
    	if(a == ' '){
    		word++;
		}
	for(i=0;i!=EOF;i++)
      for(j=i+1;j!=EOF;j++){
         if(strcmp(a[i],a[j])>0){
            strcpy(temp,a[i]);
            strcpy(a[i],a[j]);
            strcpy(a[j],temp);
         }
      }
   printf("Order of Sorted Strings:");
   for(i=0;i!+EOF;i++)
      puts(a[i]);
   
   return 0;
		}
	}
	printf("total no of words:%d",word);
	
}
