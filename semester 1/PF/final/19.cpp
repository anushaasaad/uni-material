#include<stdio.h>
#include<stdlib.h>
int main(){
    	int n,i,*ptr,sum=0;
    	printf("Enter number of elements: ");
    	scanf("%d",&n);
    	ptr=(int*)malloc(sizeof(int));
    	if(ptr==NULL){
    	    printf("Error! please alllocate some memory first!");
        	
    	}
    	printf("Enter elements of array:\n ");
    	for(i=0;i<n;++i){
        	printf("Number %d:",i+1);
        	scanf("%d",ptr+i);
        	sum=*(ptr+i)+sum;
        	printf("\n");
    	}
    	printf("Sum=%d",sum);
    	free(ptr);
    	
}
/*the thing happening here is that malloc reserves a whole block of memory for ptr whereas 
calloc only reserves separated spaces for each integer number 
but the function performed is in the same way
only the memory allocation type is different*/

