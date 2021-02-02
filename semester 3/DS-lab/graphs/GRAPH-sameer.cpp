#include <iostream>
#include<queue>
bool visited[5]={false,false,false,false,false}; 
using namespace std;

class graph{
	int v;
	int *array;
	bool *visited;
	public:
		graph(int v){
			this->v=v;
			array=new int[v]; 
			visited=new bool[v];
		}
		void add_node(int v,int d){
			array[v]=d;
		}
		void BFS(int n){
			queue <int> q;
			if(visied[n]!=true){
				q.push(n);
				visited[n]=true;
				while(q.empty()!=true){
					int s=q.front();
					cout<<s<< " ";
					q.pop();
					for(int i=0;i!=5; i++){
						if(!visited[i]){
							q.push(array[i]);
							visited[i]=true;
						}
					}
				}
			}else{
				main();
			}
		}
};
int main(){
    graph g(5);
    g.add_node(0,1);
    g.add_node(0,2);
    g.add_node(2,1);
    g.add_node(3,1);
    g.add_node(4,0);
    g.BFS(0);
    cout<<"\nBFS : ";
    return 0;
}
















