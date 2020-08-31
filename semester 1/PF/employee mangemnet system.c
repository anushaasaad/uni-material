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
		 	del();
		 	break;
		 	
		case 3:
		 	display();
		 	break;
		default:
			printf("not avaliable");
			break;
	
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
	int i,n;
	struct employee e[50];
	for(i=1; i<=n; i++){
	
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
	system("CLS");
	for(i=1; i<=n; i++){
		printf("Name of employee %d=%s",i,e[i].name);
	}
	printf("Enter which employee detail you want? %d");
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
	if (n < 3) {
                for (i=1;i<=n;i++)
                {
                    
                        printf("Enter Employee ID: ");
                        scanf("%d", &e[i].id);
                        printf("Enter Employee date of birth: ");
                        scanf("%d", &e[i].dob);
                        printf("Enter Employee Salary: ");
                        scanf("%lf", &e[i].salary);
                    
                }
                n++;
            }
    else {
                printf("ERROR!!! Maximum Number of Employees Reached\n");
            }        
}
