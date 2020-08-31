#include <stdio.h>

int check(int arr[5][5],int i,int j)
{
    int k,loop;
    for(loop=0;loop<5;loop++)
    {
        if(arr[i][loop]==1 && arr[j][loop]==1)
        {
            k=1;
        }else{
        	k=0;
		}
    }
    return k;
}
main()
{
    int arr[5][5]={
        {0,1,0,1,1},
        {1,0,1,0,1},
        {0,1,0,0,0},
        {1,0,0,0,1},
        {1,1,0,1,0}
    },i,j,k;
    printf("Enter first friend: ");
    scanf("%d",&i);
    printf("Enter second friend: ");
    scanf("%d",&j);
    k=check(arr,i,j);
    printf("Returned Value: %d",k);
}
