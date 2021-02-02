#include<iostream>
using namespace std;

int A[4][4]=
{
	1,1,1,1,
	0,0,1,0,
	0,0,1,1,
	0,0,0,1	
};

int path[4][4]=
{
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0	
};

int findPath (int i, int j, int n)
{
	
	
	if(i==n-1 && j == n-1)
	{
		path[i][j] = 1;
		return 1;
	}
	
	if(A[i][j] == 1)
	{
		path[i][j] = 1; //1
		if(findPath(i+1, j, n) == 1) return 1; //3
		if(findPath(i, j+1, n) == 1) return 1; //2
		path[i][j] = 0; //4
	}
	
	
	return 0;
	
	
}

int main()
{
	findPath(0, 0, 4);
	
	for(int i = 0; i<4; i++)
	{
		for(int j = 0; j<4; j++)
		{
			cout<<" "<<path[i][j];	
		}
		cout<<endl;
	}
	return 0;
}
