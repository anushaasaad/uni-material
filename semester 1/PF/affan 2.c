#include <stdio.h>
void rotate_right(float a[], int n) 
{
   int i;
   float t;
   for(i=n-1;i>0;i--)
   {
   	t=a[i];
   	a[i]=a[i-1];
   	a[i-1]=t;
   	}	
	
	//printing array after rotating to right//
	printf("after rotating: \n");
	 for(i=0;i<n;i++)
   {
	printf("%.1f ",a[i]); //.1 is to print the number to 1 decimal number//
   }

}
void main()
{
	int n,i,j;
	printf("Enter size of array: ");
	scanf("%d",&n);
	
	float a[n];
    
    for(i=0;i<n;i++)
    {
	printf("Enter elements of array: ");
	scanf("%f",&a[i]);
    }
    
    //printing the array after rotating to right//
    printf("before rotating: \n");
    for(i=0;i<n;i++)
    {
    	printf("%.1f ",a[i]);
	}
	printf("\n \n");
   
    rotate_right(a,n); //function call//
	
}
