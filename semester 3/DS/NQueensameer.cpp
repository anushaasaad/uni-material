#include<iostream>
#include<stdio.h>
using namespace std;

bool checkSafety(int board [4][4],int row,int col) // Never check to right e.g if placing in 3 col dont check 4 col.
{
    int i,j;
// left diagonal
    
    //1)
    // for(int i=0;i<row;i++)
    // {
    //     for(int j=0;j<col;j++)
    //     {
    //         if(i==j)
    //         {
    //             if(board[i][j])
    //             return false;
    //         }
    //     }
    // }

    //2)
    for(int i=row,j=col; i>=0 && j>=0;j--,i--)
    {
        if(board[i][j])
        return false;        
    }

// right diagonal
    for(int i=row,j=col;i<4 && j>=0;i++,j--)
    {
        if(board[i][j])
        return false;
    }
// same row on left
    for(int j=0;j<col;j++)
    {
        if(board[row][j])
        return false;
    }

    return true;      // if no violation then return treu
}

bool NQueen(int board [4][4],int col)
{
    // BASE CASE
    if (col >= 4)
    return true;

    // ACTION TO BE PERFORM
    for(int i=0;i<4;i++)   // (i(row) changes only if we want to change row but for same column)
    {
        if(checkSafety(board,i,col))
        {
            board[i][col]=1;   // Queen place successfully
            
            // RECURSIVE CALL
            if(NQueen(board,col+1))// Now we should place next Queen (RC only accurrs to change column and row is reset to 0) 
            return true;
            
            // ACTIONS TO BE UNDONE AND BACKTRACKING (undo previous action)
            else 
            board[i][col]=0;
        }
    }
    // No Solution (e.g if we take N=5 in 4x4 grid) rarely used 
    return false;
}

int  main()
{
    int board[4][4]={
                    {0,0,0,0},
                    {0,0,0,0},
                    {0,0,0,0},
                    {0,0,0,0}
                    };

    if(NQueen(board,0));
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }    

}
