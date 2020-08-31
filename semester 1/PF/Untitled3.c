#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
	int id;
	char name[20];
	float per;
	
}s[100];
int main()
{
	int n,i,t=0,len;
	printf("how many record you want to enter:");
	scanf("%d",&n);
	int *p;
	p=(int*)calloc(n,sizeof(int));
	for(i=0; i<n; i++){
		printf("name:");
		scanf("%s",s[i].name);
		printf("id:");
		scanf("%d",&s[i].id);
		printf("percentage:");
		scanf("%f",&s[i].per);
	}
	for(i=0; i<n; i++){
		if(s[i].name[0]=='a' || s[i].name[0]=='A'){
			printf("name:%s\n",s[i].name);
			printf("id:%d\n",s[i].id);
			printf("percentage:%f\n",s[i].per);
			printf("\n");
		}
	}
}

