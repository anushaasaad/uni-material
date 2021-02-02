#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
vector <int> graph[5];
bool visited[5]={false,false,false,false,false}; 

void ADD(int a,int b)
{
    graph[a].push_back(b);
}
void DFS(int x) 
{
    stack<int>st;
    
    st.push(x);
    visited[x]=true; 

    while(!st.empty())
    {
        int n =st.top();  
        cout<< n<<" ";
        st.pop(); 

        for(int i=0;i<graph[n].size();i++)
        {
            if( ! visited[ graph[n][i] ]) 
            {
                st.push(graph[n][i]);   
                visited[graph[n][i]]=true; 
            }
        }
    }
}
void BFS(int s) 
{
    queue<int>st;
    
    st.push(s); 
    visited[s]=true; 

    while(!st.empty())
    {
        int u =st.front();  
        cout<< u<<" ";
        st.pop();     

        for(int i=0;i<graph[u].size();i++) 
        {
            if( ! visited[ graph[u][i] ])
            {
                st.push(graph[u][i]);    
                visited[graph[u][i]]=true; 
            }
        }
    }
}

int main(){
    ADD(5,3);
	ADD(0,2);
    ADD(6,3);
    ADD(8,4);
    ADD(2,1);
    ADD(9,0);

    cout<<"DFS : ";
    DFS(0);

    for(int i=0;i<5;i++)
    visited[i]=false;

    cout<<"\nBFS : ";
    BFS(0);
    return 0;
}
