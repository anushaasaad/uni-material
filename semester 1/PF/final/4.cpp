#include<stdio.h>
#include<stdlib.h>
void Input();
Capacity(float g,float (*p1)[2][2]);
int main()
{
	Input();
	
	
}
void Input()
{
	float guests,p[2][2];
	float t1[3][2]={{2500,50},{5000,100},{7500,120}};
	
	float t2[3][3]={{1,5,500},{2,10,750},{3,15,1000}};
	char *ptr1[3]={"Small Hall","Terrace","Great Hall"};
	char *ptr2[3]={"normal","gold","platinium"};
	printf("Enter the total number of guests: ");
	scanf("%f",&guests);
	Capacity(guests,&p);
}
Capacity(float g,float (*p1)[2][2])
{
	 
	if(g<50)
	p1[0][0]={{g,2500/g}};
	printf("%f",*(*p1+0));
	
	
}

