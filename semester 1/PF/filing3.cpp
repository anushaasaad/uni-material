#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
int main()
{
	int l,count;
	char a[100];
	char ch;
	FILE *fp;
	FILE *fp1;
	fp=fopen("deleting.txt","a+");
	
	if (fp==NULL ){
		printf("file cannot open");
	}
	ch= getch();
	while(ch=='y'){
		printf("enter anything?:");
    	scanf("%s",a);
    	fflush(stdin);
        fprintf(fp, "%s\n", a);
        printf("do you want to enter another line?:");
        ch = getche();
	}
	rewind(fp);
	if(ch!='y'){
		while (fscanf(fp, "%s", a) != EOF){
        count++;
   		}
	}
	printf("Do You want to delete? ");
    ch=getch();
    if (ch == 'y')
		fp1=fopen("deleting1.txt","w");
	
	while(ch=='y'){
	
	printf("no of lines=%d", count);
	printf("enter line you want to delete");
	scanf("%d",&l);
	rewind(fp);
	count = 0;
	while (fscanf(fp, "%s", a) != EOF){
		if(l!=count){
			fprintf(fp1,"%s\n",a);	
		}
		count++;
	}
	
	fclose(fp);
	fclose(fp1);
	remove("deleting.txt");
	rename("deleting1.txt","deleting.txt");
	printf("Delete another line(y/n)");
    fflush(stdin);
    ch = getche();
	}
}
