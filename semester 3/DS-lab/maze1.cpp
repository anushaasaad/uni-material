#include<iostream>
#include<conio.h>
using namespace std;
class maze
{
public:
	maze(){}
	bool check_position(int maze[][4],int x,int y)
	{
		if(maze[x][y]==1)
		{return true;}
		else
		{return false;}
	}
	bool finding_path(int maze[][4],int result[][4],int x,int y,int size)
	{
		if(x==size-1&&y==size-1&&maze[x][y]==1)
		{
			result[x][y]=1;
			for(int i=0;i<size;i++)
			 {
				for(int j=0;j<size;j++)
					{
						cout<<result[i][j];
						cout<<" ";
					}
				cout<<endl;
			 }
			return true;
		}
		if(check_position(maze,x,y))
		{
			result[x][y]=1;
			if(finding_path(maze,result,x+1,y,size))
			{return true;}
			if(finding_path(maze,result,x,y+1,size))
			{return true;}
			result[x][y]=0;
		}
		return false;
	}
	void first_step(int maze[][4],int size)
	{
		int result[4][4]={
						{0,0,0,0},
						{0,0,0,0},
						{0,0,0,0},
						{0,0,0,0}
					};
		if(finding_path(maze,result,0,0,size))
		{
			cout<<"HURRAH!WE GOT IT BYE BYE"<<endl;
		}
		else
		{
			cout<<"ALAS!CAN'T FIND A PATH"<<endl;
		}
	}
};
int main()
{
	maze m1;
	int maze[4][4]={
						{1,0,0,0},
						{1,1,1,0},
						{1,0,1,1},
						{0,0,0,1}
					};
	int size=4;
	m1.first_step(maze,size);
	getch();
}
