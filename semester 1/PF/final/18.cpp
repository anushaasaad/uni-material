#include<stdio.h>
#include<stdlib.h>
int main(){
    	int n,i,*ptr,sum=0;
    	printf("Enter number of elements: ");
    	scanf("%d",&n);
    	ptr=(int*)calloc(n,sizeof(int));
    	if(ptr==NULL){
    	    printf("Error! please enter some memory allocation first!.");
        	exit(0);
    	}
    	printf("Enter elements of array: \n");
    	for(i=0;i<n;i++){
    		printf("Number %d:",i+1);
        	scanf("%d",ptr+i);
        	sum=*(ptr+i)+sum;
        	printf("\n");
    	}
    	printf("Sum= %d ",sum);
    	free(ptr);
    	
}
