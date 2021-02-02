#include <iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
vector<int> ob[5];
bool visited[5]={false};
class graph{
	int v;
	public:
		graph(int v)
		{
			this->v=v;
			vector<int> ob[v];
		}
		void addnode(int v,int u){
			ob[v].push_back(u);
			ob[u].push_back(v);
		}
		void dfs(int s){
			stack<int> st;
			st.push(s);
			visited[s]=true;
			
			while(!st.empty()){
				int x=st.top();
				cout<<x <<" ";
				st.pop();
				for(int i=0; i<ob[x].size(); i++){
					if(!visited[ob[x][i]]){
						st.push(ob[x][i]);
						visited[ob[x][i]]=true;
					}
				}
			}
			
		}
		void bfs(int s){
			queue<int> q;
			for(int i=0; i < v; i++)
                visited[i] = false;
			q.push(s);
			visited[s]=true;
			
			while(!q.empty()){
				int x=q.front();
				cout<<x <<" ";
				q.pop();
				for(int i=0; i<ob[x].size(); i++){
					if(!visited[ob[x][i]]){
						q.push(ob[x][i]);
						visited[ob[x][i]]=true;
						
					}
				}
			}
			
		}
};
int main(){
	graph g(5);
	g.addnode(0,1);
	g.addnode(0,2);
	g.addnode(0,3);
	g.addnode(1,4);
	g.addnode(2,4);
	g.addnode(3,4);
	g.dfs(0);
	cout<<endl;
	g.bfs(1);
	
}
