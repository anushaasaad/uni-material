#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
struct hardware{
	int rec;
	char name[20];
	int q;
	int cost;
}r;
int main()
{
    int choice,b,c,count=0,record;
    int del;
    char ch='y';
    FILE *fp;
    FILE *fp2;
    
    printf("1 to add a tool record\n2 to delete a record\n3 to display all the records\n4 to update a record");
    scanf("%d",&choice);
    
    if(choice==1){
    	fp=fopen("Hardware.txt","a");
    	if(fp==NULL){
    		printf("file cannot open.");
    		return 0;
		}
		while(ch=='y'){
			printf("\nenter a tool record ");
			scanf("%d",&r.rec);
			if(r.rec>100 || r.rec<0){
				printf("record not found");
			}else
			printf("\nthe name of tool ");
			scanf("%s",&r.name);
			printf("the quatity of tool ");
			scanf("%d",&r.q);
			printf("the cost of tool ");
			scanf("%d",&r.cost);
			fprintf(fp,"%d\t%s\t%d\t%d\n",r.rec, r.name, r.q, r.cost);
			printf("\nWant to add another input? (y/n)");
	            fflush (stdin);
	            ch=getche();
	    }
	    fclose(fp);
			
		}
		if(choice==2){
			while(ch=='y'){
				printf("enter record you want to delete ");
			    scanf("%d",&del);
			    fp=fopen("Hardware.txt","r");
			    fp2=fopen("Hardware2.txt","w");
			    rewind(fp);
			    while(fscanf(fp,"%d\t%s\t%d\t%d\n",&r.rec,&r.name,&r.q,&r.cost)!=EOF){
			    	if(r.rec!=del){
			    		fprintf(fp2,"%d\t%s\t%d\t%d\n",r.rec, r.name, r.q, r.cost);
					}
				}
			fclose(fp);
			fclose(fp2);
			remove("Hardware.txt");
			rename("Hardware2.txt","Hardware.txt");
			printf("Delete another record(y/n)");
            fflush(stdin);
            ch = getche();	
		}
	}
	if(choice==3){
		fp=fopen("Hardware.txt","r");
		if(fp==NULL){
    		printf("file cannot open.");
    		return 0;
		}
		rewind(fp);
		while(fscanf(fp,"%d\t%s\t%d\t%d\n",&r.rec,&r.name,&r.q,&r.cost)!=EOF){
		
			    printf("%d\t%s\t%d\t%d\n",r.rec, r.name, r.q, r.cost);
	}
	fclose(fp);	
	}
	if(choice==4){
	fp=fopen("hardware.dat","r");
	fp2=fopen("hardware2.dat","w");
	if(fp==NULL || fp2==NULL){
    		printf("file cannot open.");
    		return 0;
		}
	printf("enter the record you want to update:");
	scanf("%d",&record);
	fflush(stdin);
	while(fscanf(fp,"%d\t%s\t%d\t%d\n",&r.rec,&r.name,&r.q,&r.cost)!=EOF)
	{
	  if(r.rec==record)
		{
            printf("input the tool record: ");
            scanf("%d",&r.rec);
            fflush(stdin);
            printf("input the tool name: ");
            gets(r.name);
            fflush(stdin);
            printf("input the tool price: ");
            scanf("%f",&r.cost);
            printf("input the tool quantity:");
            scanf("%d",&r.q);
           	fprintf(fp2,"%d\t%s\t%d\t%d\n",r.rec, r.name, r.q, r.cost);
            count++;
		}
	else
        {
		fprintf(fp2,"%d\t%s\t%d\t%d\n",r.rec, r.name, r.q, r.cost);
        }
	}
	if(count==0)
	{
		system("CLS");
		printf("\ntool does not exist\n");
	}
	fclose(fp2);
	fclose(fp);
	remove("hardware.dat");
	rename("hardware2.dat","hardware.dat");
	system("CLS");
	return 0;
}
}

