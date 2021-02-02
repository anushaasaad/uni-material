#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;
void search(int row, int col,char b[row][col]){
	int i, j;
	for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				cout<<b[i][j] <<" ";
			}
			cout<<"\n";
	}
	int n;
	string word[5];
	cout<<"enter Number of words: " <<endl;
	cin>>n;
	for(int j=0;j<n;j++){
		cin>> word[j];
	}
	int x,m;
	int score[5];
	// horizontal forward search	
	for( x=0; x<n; x++)
	{
		int str=word[x].length();
		for(i=0;i<row;i++)
	    {
		    int k=0;
		    for(j=0;j<col;j++)
		    {
			    if(word[k][x]==b[i][j])
			    {
			    	word[k][x];
			    	if(k==str-1)
			    	{
			    		k=0;
			    		score[x]++;
					}
				    k++;
			    }
		    }
	    }
	}
	//vertical downward
	for( x=0; x<n; x++)
	{
		int str=word[x].length();
	//	score[l]=0;
		for(i=0 , j=0; i<row && j<col; i++)
	    {
		    int k=0;
			    if(word[k][x]==b[i][j])
			    {
			    	word[k][x];
			    	if(k==str-1)
			    	{
			    		k=0;
			    		score[x]++;
					}
				    k++;
			    }
		    }
	    }
	// upper diagnol 
	for( x=0; x<n; x++)
	{
		int str=word[x].length();
	//	score[l]=0;
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
	    {
		    int k=0;
			    if(word[k][x]==b[i][j])
			    {
			    	if(k==str-1)
			    	{
			    		word[k][x];
			    		k=0;
			    		score[x]++;
					}
				    k++;
			    }
		    }
	    }
	//lower diagnol
	for( x=0; x<n; x++)
	{
		int str=word[x].length();
	//	score[l]=0;
	for (i = row, j = col; j >= 0 && i < col; i++, j--) 
	    {
		    int k=0;
			    if(word[k][x]==b[i][j])
			    {
			    	cout<<word[k][x];
			    	if(k==str-1)
			    	{
			    		k=0;
			    		score[x]++;
					}
				    k++;
			    }
		    }
	    }
	cout<<"score: " <<score[x] <<endl;
}
int main()
{
	int row,col;
	cout<<"Enter size of rows and columns: " <<endl;
	cin>>row;
	cin>>col;
	char b[3][14] = { "GEEKSFORGEEKS", 
                      "GEEKSQUIZGEEK", 
                      "IDEQAPRACTICE"}; 
	//input of board
	/* cout<<"enter elements of the board:" <<endl;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			cin>>b[i][j];
		}
		//cout<<"\n";
	}*/
	search(row,col,&b[3][14]);
}

