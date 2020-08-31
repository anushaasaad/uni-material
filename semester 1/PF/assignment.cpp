#include <stdio.h>
struct employee{
	char name[20];
	int id[10];
	int dob[20];
	char dep[30];
	float salary[20];
}e[3];
int main()
{
struct employee e1={"ANUSHA",1100,290401,"COMPUTER SCIENCE",40000.0};
struct employee e2={"HADIQA",1120,071101,"HUMAN RESOURCES ",45000.0};
struct employee e3={"NOOR",1200,121203,"ENGINEERING DEPARTMENT",35000.0};
int n,a,b,c,i;
FILE *fp;
fp=fopen("EMPLOYEE MANAGEMENT SYSTEM.txt","w");
if(fp==NULL)
{
	printf("FILE CANNOT BE OPENED : ");
	return 0;
}
fprintf(fp,"%s %d %s %s %f", e1.name,e1.id,e1.dob,e1.dep,e1.salary);
fprintf(fp,"%s %d %s %s %f", e2.name,e2.id,e2.dob,e2.dep,e2.salary);
fprintf(fp,"%s %d %s %s %f", e3.name,e3.id,e3.dob,e3.dep,e3.salary);
printf("ENTER 1 TO ADD AN EMPLOYEE RECORD .\n ENTER 2 TO DELETE AN EMPLOYEE RECORD\n ENTER 3 TO DISPLAY EMPLOYEE RECORD");
scanf("%d",&n);
if(n==1)
{
	fp=fopen("EMPLOYEE MANAGEMENT SYSTEM.txt","w");
	if(fp==NULL)
	{
		printf("FILE CANNOT BE OPENED .");
		return 0;
	}
	printf("HOW MANY RECORDS YOU WANT TO ENTER ");
	scanf("%d",&a);
	for(i=3;i<a+3;i++)
	{
	printf("Name = ");
    scanf("%s",&e[i].name);
    printf("Department=");
    scanf("%s",&e[i].dep);
    printf("Dateofbirth =");
    scanf("%d",&e[i].dob);
    printf("ID =");
    scanf("%d",&e[i].id);
    printf("Salary=");
    scanf("%d",&e[i].salary);
	}
	fclose(fp);
	}
	
if(n==2)
{
	
	fp=fopen("EMPLOYEE MANAGEMENT SYSTEM.txt","w");
	if(fp==NULL)
	{
		printf("FILE CANNOT BE OPENED .");
		return 0;
	}
	
	printf("WHICH EMPLOYEE RECORD  YOU WANTS TO DELETE \n ENTER HER ID OR HIS ID : ");
	scanf("%d",&b);
	for(i=3;i<100;i++)
	{
		if(e[i].id==b)
		{
			e[i]=NULL;	
		}		
	}
	fclose(fp);
}
if(n==3)
{
	fp=fopen("EMPLOYEE MANAGEMENT SYSTEM.txt","w");
	if(fp==NULL)
	{
		printf("FILE CANNOT BE OPENED .");
		return 0;
	}
	printf("WHICH EMPLOYEE RECORD  YOU WANTS TO DISPLAY \n ENTER HER ID OR HIS ID : ");
	scanf("%d",&c);
	for(i=3;i<100;i++)
	{
		if(e[i].id==c)
		{
		  printf("%s\n%s\n%d\n%s\n%d",e[i].name,e[i].dep,e[i].id,e[i].dob,e[i].salary);
			
		}
		
	}
	fclose(fp);
}		

	fclose(fp);	
}




