#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student{
	int id;
	char name[20];
	float percentage;
};

int main () {
	struct student *ptr;
	printf("Enter The total number of students ");
	int d;
	scanf("%d",&d);
	ptr=(struct student*)malloc(d* sizeof(struct student));
	if (ptr == NULL){
		printf("No space Created");
	}
	int i;
	for(i=0;i<d;i++){
		printf("\nEnter Name \n");
		scanf("%s",(ptr+i)->name);
		printf("\nEnter Id \n");
		scanf("%d",&(ptr+i)->id);
		printf("\n Enter Percentage \n");
		scanf("%f",&(ptr+i)->percentage);
		
		
		
	}
		for(i=0;i<d;i++){
			if (*(ptr+i)->name=='A'){
				printf("\nName %s\n",(ptr+i)->name);
				printf("\nid is %d",(ptr+i)->id);
				printf("\nPercentage %.2f\n",(ptr+i)->percentage);
		
			}
		
		
		
	}
	
}
