#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
int main ()
{
	struct employee 
	{
		char name[20];
		int id; 
		char dep[20];
		int salary; 
		char dob[20]; 
	}; 
	struct employee e; 
	int n,b,c,i;
	int del; 
	char ch='y';
	FILE *fp;
	FILE *fp2;
	
	printf("1 to add an employee detail.\n2 to delete an employee detail.\n3 to display .\n");
	scanf("%d", &n); 
	if(n==1)
	{
		fp=fopen("Employee management system.txt", "a");
	    if(fp==NULL)
	    {
	    	printf("File cannot be opened.");
		    return 0;
		}
		while(ch=='y')
		{
		
	    		printf("\nEnter the employee name ");
		        scanf("%s", e.name);
		        printf("Enter the employee Date of Birth ");
		        scanf("%s", e.dob);
		        printf("Enter the employee ID ");
		        scanf("%d", &e.id);
		        printf("Enter the employee department ");
		        scanf("%s", e.dep);
		        printf("Enter the emmployee's salary ");
		        scanf("%d", &e.salary);
	            fprintf(fp, "%s\t%s\t%d\t%s\t%d\n", e.name, e.dob, e.id, e.dep, e.salary); 
	            printf("\nWant to add another input? (y/n)");
	            fflush (stdin);
	            ch=getche();
	    }
	    fclose(fp);
	}
	if(n==2)
	{
		while(ch== 'y')
            {
                printf("\nEnter ID to delete ");
                scanf("%d", &del);
                fp=fopen("Employee management system.txt", "r");
                fp2 = fopen("Employee management system2.txt","w"); 
                rewind(fp); 
                while(fscanf(fp, "%s %s %d %s %d", e.name, e.dob, &e.id, e.dep, &e.salary) != EOF)  
                {
                    if(e.id!=del)  
                    {
                    	fprintf(fp2, "%s %s %d %s %d", e.name, e.dob, e.id, e.dep, e.salary);
                       
                    }
                }
                fclose(fp);
                fclose(fp2);
                remove("Employee management system.txt");
                rename("Employee management system2.txt","Employee management system.txt"); 
                printf("Delete another record(y/n)");
                fflush(stdin);
                ch = getche();
            }
	}
	if(n==3)
	{
		fp=fopen("Employee management system.txt", "r");
		if(fp==NULL)
		{
			printf("File cannot be opened");
		}
		rewind(fp);
        while(fscanf(fp, "%s %s %d %s %d", e.name, e.dob, &e.id, e.dep, &e.salary) != EOF ) 
        {
            printf("%s\t%s\t%d\t%s\t%d\n",e.name,e.dob,e.id, e.dep, e.salary); 
            
        }
        fclose(fp);
            
   }
}

             
