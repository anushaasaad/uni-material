#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
int main(){
	struct employee 
	{
		char name[25];
		char dob[40]; 
		int id; 
		char dep[30];
		int salary; 
	}; struct employee e; 
	int n, b, c, i;
	int del; 
	char ch='y';
	FILE *fp;
	FILE *fp2;
	
	printf("1 add an employee detail.\n2 delete an employee detail.\n3display.\n");
	scanf("%d", &n); 
	if(n==1)
	{
		fp=fopen("Employee system management.txt", "a");
	    if(fp==NULL)
	    {
	    	printf("File cannot be opened.");
		    return 0;
		}
		while(ch=='y')
		{
		
	    		printf("\nEnter the employee name= ");
		        scanf("%s", e.name);
		        printf("Enter the employee Date of birth=");
		        scanf("%s", e.dob);
		        printf("Enter the employee ID=");
		        scanf("%d", &e.id);
		        printf("Enter the employee department=");
		        scanf("%s", e.dep);
		        printf("Enter the emmployee salary=");
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
                printf("\nEnter ID of the employee to delete:");
                scanf("%d", &del);
                fp=fopen("Employee management system.txt", "r");
                fp2 = fopen("Employee management system2.txt","w");  /// create a intermediate file for temporary storage
                rewind(fp); /// move record to starting of file
                while(/*fread(&e,sizeof(e),1,fp)*/fscanf(fp, "%s %s %d %s %d", e.name, e.dob, &e.id, e.dep, &e.salary) != EOF)  /// read all records from file
                {
                    if(e.id!=del)  /// if the entered record match
                    {
                    	fprintf(fp2, "%s %s %d %s %d", e.name, e.dob, e.id, e.dep, e.salary);
                        // fwrite(&e,sizeof(e),1,fp2); /// move all records except the one that is to be deleted to temp file
                    }
                }
                fclose(fp);
                fclose(fp2);
                remove("Employee management system.txt"); /// remove the orginal file
                rename("Employee management system2.txt","Employee management system.txt"); /// rename the temp file to original file name
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
			printf("File cannot be opened.");
		}
		rewind(fp); ///this moves file cursor to start of the file
        while(/*fread(&e,sizeof(e),1,fp)*/ fscanf(fp, "%s %s %d %s %d", e.name, e.dob, &e.id, e.dep, &e.salary) != EOF ) /// read the file and fetch the record one record per fetch
        {
            printf("%s\t%s\t%d\t%s\t%d\n",e.name,e.dob,e.id, e.dep, e.salary); /// print the name, age and basic salary
            
        }
        fclose(fp);
            
   }
		
	
		
	
}
