#include <stdio.h>
//#define SIZE 3

int main()
{
     
    
    int i,j,S,r,c;
    printf("Enter the number of rows:");
    scanf("%d",&r);
    printf("Enter the number of coulmns:");
    scanf("%d",&c);
    int A_not[r][c]; 
    int B_done[r][c]; 

    printf("Enter elements in matrix \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
        	printf("Enter the number at position (%d)(%d):",i,j);
            scanf("%d", &A_not[i][j]);
        }
    }

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            B_done[i][j] = A_not[j][i];
        }
    }

 
    for(i=0,S=1;i<r && S;i++)
    {
        for(j=0;j<c;j++)
        {
            if(A_not[i][j] != B_done[i][j])
            {
                S=0;
                break;
            }
        }
    }

    if(S==1)
    {
        printf("Matrix is Symmetric matrix: \n");

       
    }
    else
    {
        printf("Your matrix is not Symmetric matrix.");
    }

    return 0;
}
