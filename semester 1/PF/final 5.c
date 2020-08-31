//Dates are commonly printed in several different formats in business correspondence. Two
//of the more common formats are 07/21/2003 and July 21, 2003 Write a program that reads
//a date in the first format and prints it in the second format
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main()
{
	char *month[12]={"january","febuary","march","april","may","june","july","august","september","october","november","december"};
	int m,d,y;
	printf("enter date :");
	scanf("%d",&m);
	scanf("%d",&d);
	scanf("%d",&y);
	printf("first format:%d/%d/%d\n",m,d,y);
	printf("final format:%s %d,%d",month[m],d,y);
}
