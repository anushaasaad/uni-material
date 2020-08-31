#include <stdio.h>
#include <windows.h>
int choice1();
int add();
int details();
struct employee{
	char name[20];
	int id[10];
	int dob[20];
	char dep[30];
	int salary[20];
	
}e={
	"anusha",1,120102,"cs",12000,
	"hamza",2,130319,"ee",13000,
	"sharjeel",3,2940508,"mba",14000,
	"ahsan",4,130807,"bba",15000,
	"hadiqa",5,140918,"bs",16000,
};
int main()
{
	int choice=choice1();
	system("CLS");
	switch (choice)
	{
		case 1:
			add();
			break;
		
		case 2:
		 
		 	break;
		 	
		case 3:
		 	details();
		 	break;
		default:
			printf("not avaliable");
			break;
	
}
}
int choice1()
{
	
	int choice;
	printf("                 EMPLOYEE MANAGEMNET SYSTEM\n");
	printf("                ****************************\n");
	printf("____________________________________________________________________\n");
	printf("||             1- add emplyee                                     ||\n");
	printf("||             2- delete employee                                 ||\n");
	printf("||             3- display employee                                ||\n");
	printf("||________________________________________________________________||\n");
	printf("  Enter your choice: ");
	scanf("%d",&choice);
	
	return (choice);
}
	

int details()	
{
	FILE *fp;
	fp = fopen("employee managment system", "w");
	if(fp==NULL){
		printf("File cannot open");
		exit(1);
	}
	int i,n=5;
	//printf("enter how many?");
	//scanf("%d",&n);
	//struct employee e[50];
	//for(i=1; i<=n; i++){
	
	//	printf("Name = ");
	//	scanf("%s",&e[i].name);
      //  printf("Department=");
        //scanf("%s",&e[i].dep);
       // printf("Dateofbirth =");
        //scanf("%d",&e[i].dob);
       // printf("ID =");
       // scanf("%d",&e[i].id);
       // printf("Salary=");
       // scanf("%d",&e[i].salary);
	//}
	system("CLS");
	for(i=1; i<=n; i++){
		
		printf("Name of employee %d=%s\n",i,e.name);
	}
	printf("Enter which employee detail you want?");
	scanf("%d",&i);
	if(i==i){
	printf(" \n                   ||*********************************||");
	printf(" \n                   ||       EMPLOYEE DETAILS          ||");
	printf(" \n                   ||*********************************||");
	printf(" \n                        NAME=%s                       ",e[i].name);
	printf(" \n                        DEPARTMENT=%s                      ",e[i].dep);
	printf(" \n                        DATE OF BIRTH=%d                    ",e[i].dob);
	printf(" \n                        ID=%d                      ",e[i].id);
	printf(" \n                        SALARY=%d                  ",e[i].salary);
	fprintf(fp, "%s %s %d %d %d", e[i].name,e[i].dep, e[i].dob, e[i].id, e[i].salary);
	
}
}
int add()
{
	struct employee e[50];
	int n,i;
	system("CLS");
	printf("only 3 employee details can be added at one time\n");
	printf("enter how many?");
	scanf("%d",&n);
	if (n<=3) {
                for (i=1;i<=n;i++)
                {
                	printf("enter details for %d employee\n",i);
                	    printf("Name = ");
		                scanf("%s",&e[i].name);
                        printf("Department=");
                         scanf("%s",&e[i].dep);
                         printf("Enter Employee ID: ");
                        scanf("%d", &e[i].id);
                        printf("Enter Employee date of birth: ");
                        scanf("%d", &e[i].dob);
                        printf("Enter Employee Salary: ");
                        scanf("%d", &e[i].salary);
                }
            }
    else {
                add();
            } 
			for(i=1; i<=n; i++){
			
                                printf("\nprinting details for %d employee\n",i);
                            	printf(" \n                        NAME=%s",e[i].name);
                              	printf(" \n                        DEPARTMENT=%s",e[i].dep);
	                            printf(" \n                        DATE OF BIRTH=%d",e[i].dob);
	                            printf(" \n                        ID=%d ",e[i].id);
	                            printf(" \n                        SALARY=%d",e[i].salary);
	                        }
                    
   
}
int del()
{
	
}

