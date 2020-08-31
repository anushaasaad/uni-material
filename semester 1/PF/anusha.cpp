#include <stdio.h>
#include<stdlib.h>
struct customer{
		char name[20];
		int no[10];
		char address[20];
	};
int main()
{
	struct customer c;
	int i,j,a[i],count=0;
	for(i=1; i<=100; i++){
		if(a[i]==0){
			printf("%d\t",i);
		}else{
			printf("%d\t",i);
		}
		if(i%10==0){
			printf("\n\n");
		}
	}
	printf("ENTER SEAT YOU WANT?=");
	scanf("%d",&j);
	
	if(j>100 || j<1){
		printf("invalid seat number");
		printf("RE-ENTER SEAT YOU WANT?=");
	    scanf("%d",&j);
	}
	if(a[j]==1){
		printf("this seat is already booked.. enter another seat?");
		scanf("%d",&j);
	}else{
		a[j]=1;
	}
	printf("ENTER YOUR NAME? = ");
	scanf("%s",&c.name);
	printf("ENTER YOUR CONTACT NO? = ");
	scanf("%d",&c.no);
	printf("ENTER YOUR ADDRESS? = ");
	scanf("%s",&c.address);	
	
	
	
	printf(" \n                     ***************************");
	printf(" \n                     CUSTOMER TICKET INFORMATION");
	printf(" \n                     ****************************\n");
	printf("                         NAME=%s\n",c.name);
	printf("                         ADDRESS=%s\n",c.address);
	printf("                         CONTACT NO=%d\n",c.no);
	printf("                         SEAT NO=%d",j);
}                      
