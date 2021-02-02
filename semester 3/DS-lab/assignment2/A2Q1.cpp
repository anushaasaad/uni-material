#include <iostream>
#include <string>
using namespace std;
const int i=4;
const int j=7;
void print(char maze[i][j],int x, int y){
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			if(maze[i][j]==1){
				cout<<"("<<i<<","<<j<<")";
			}
		}
	}
}
int check(int x, int y, int dest_x, int dest_y,char (&maze)[i][j] , std::string& path) {
	if(maze[x][y]=='e'){
			print(maze,4,7);
			cout<<"("<<i<<","<<j<<")";
			int cost=0;
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					if(maze[i][j]==1){
						cost=cost+1;
					}
				}
	}
  	if (x < 0 || y < 0 || x >= dest_x|| y >= dest_y || maze[y][x]==1) {
    return 0;        
  	}else{
  		maze[x][y]=0;
  		check (x + 1, y, dest_x, dest_y, maze, path);
	    check (x , y + 1, dest_x, dest_y, maze, path);
	    check (x - 1, y, dest_x, dest_y, maze, path);
	    check (x , y - 1, dest_x, dest_y, maze, path);
	    maze[x][y]=1;
	    
	}
			cout<<"\n";
			
		}
  int len = path.size();
  path += (char) ('0' + x);
  path += ',';
  path += (char) ('0' + y);
}


int main() {
  char maze[4][7] = {
      {'s',0,0,0,0,0,1,},
      {0,1,1,0,0,1,0,  },
      {0,1,1,0,0,1,0,  },
      {0,0,0,'e',0,0,0}};
      for(int i=0; i<4; i++){
      	for(int j=0; j<7; j++){
      		if(maze[i][j]=='s'){
		     	std::string path;
		 		cout<< check(i, j, 4, 7, maze, path);
}
}
}}
