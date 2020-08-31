#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
struct employee{
	char name[20];
	int id;
	int salary;
	char dep;
	int dob;
};
int main(){
	struct employee e;
	int n,del;
	char ch='yes';
	printf("1.add another employee\n2.delete employee detail\n3.display");
	scanf("%d",&n);
	FILE *fp;
	FILE *fp2;
	
	if(n==1){
			fp=fopen("Employee managemnent system.txt","a");
			if(fp==NULL){
				printf("file cannot open");
				return 0;
			}else
			while(ch=='yes'){
				printf("Enter the employee name= \n");
		        scanf("%s", e.name);
		        printf("Enter the employee ID:");
		        scanf("%d", &e.id);
		        printf("Enter the employee department:");
		        scanf("%s", e.dep);
		        printf("Enter the emmployee salary=\n");
		        scanf("%d", &e.salary);
		        printf("Enter the employee Date of Birth=\n");
		        scanf("%s", &e.dob);
	            fprintf(fp, "%s\t%s\t%d\t%s\t%d\n", e.name, e.dob, e.id, e.dep, e.salary); 
	            printf("\nWant to add another input? (yes/no)");
	            fflush (stdin);
	            ch=getche();
			}
			fclose(fp);
		}
		
	
}
