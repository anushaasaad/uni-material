#include <stdio.h>
int pattern(int n);
int main()
{
	int n=5;
	pattern(n);
}



int pattern (int n)
{
    if (n==1)
 {
 printf("*");                     
 printf("\n");
 }

 else if(n>1)
 {

     int i;
     pattern(n-1);
     printf("*");                
     for (i=0;i<n;i++)
     printf("*");
     printf("\n");
 }
}  
