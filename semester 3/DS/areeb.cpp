#include<iostream>
using namespace std;
char array[][7]=   {    's', '0', '0', '0', '0', '0', '1',
                        '0', '1', '1', '0', '0', '1', '0',
                        '0', '1', '1', '0', '0', '1', '0', 
				        '0', '0', '0', 'e', '0', '0', '0'
				   };
void printsol(int **sol,int row,int col){
for(int i=0;i<row;i++){
for(int j=0;j<col;j++){
		if(sol[i][j]==1){
				cout<<"("<<i<<","<<j<<")";
			}
		}
	}
}
void printcost(int **sol,int row,int col){
    int cost=0;
    for(int i=0;i<row;i++){
for(int j=0;j<col;j++){
		if(sol[i][j]==1){
			cost=cost+1;
			}
			
		}
		
	}
	cout<<" Cost:"<<cost+1;
	cost=0;
}

	void pathfinder(int **sol,int row,int col,int i,int j){
		
		if(array[i][j]=='e'){
		
			printsol(sol,4,7);
			cout<<"("<<i<<","<<j<<")";
			printcost(sol,4,7);
			cout<<"\n";
			return;
		}
		
		if(i>=4|| i<0 || j>=7 || j<0 || array[i][j]=='1'||sol[i][j]==1){
			return;
		}
		else{
			sol[i][j]=1;
			pathfinder(sol,4,7,i-1,j);
			pathfinder(sol,4,7,i+1,j);
			pathfinder(sol,4,7,i,j-1);
			pathfinder(sol,4,7,i,j+1);
			sol[i][j]=0;
			return;
		}
		
	}
	
void inmaze(int row,int col,int starting_i,int starting_j){
	int** sol=new int*[row];
	for(int i=0;i<row;i++){
		sol[i]=new int[col];
	}
	pathfinder(sol,4,7, starting_i,starting_j);
	
}
	

int main(){
		
int starting_i;
int starting_j;
for(int i=0;i<4;i++){
for(int j=0;j<7;j++){
if(array[i][j]=='s'){
starting_i=i;
starting_j=j;
}
}
}		
int i=0;
int j=0;			
		
inmaze(4,7,starting_i,starting_j);
	
	
}
