#include <stdio.h>

int main()
{
    int i,j,S,r,c,L;
    printf("Enter the number of rows:");
    scanf("%d",&r);
    printf("Enter the number of coulmns:");
    scanf("%d",&c);
    int A[r][c]; 
    
    printf("Enter elements in matrix : \n");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            	printf("Enter the number at position (%d)(%d):",i,j);
            scanf("%d", &A[i][j]);
        }
    }
    L= 1;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(j>i && A[i][j]!=0)
            {
                L=0;
            }
        }
    }

    if(L== 1)
    {
        printf("\nMatrix is a Lower triangular matrix! \n");

    
    }
    else
    {
        printf("\nMatrix is not a Lower triangular matrix");
    }

    
}

