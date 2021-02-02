#include<iostream>
#include<queue>
using namespace std;
class Graph {
    private:
        int **graph;
        int vertices;
    public:

        Graph(int v) {
            vertices = v;
            graph = new int*[vertices];
            for(int i=0; i < vertices; i++)
                graph[i] = new int[vertices];
                
                
            for(int i=0; i < vertices; i++) 
                for(int j=0; j < vertices; j++)
                    graph[i][j] = 0;
            
        }

        

        void insert(void) {
            for(int i=0; i < vertices; i++) {
                for(int j=0; j < vertices; j++) {
                    cout << "\nEnter edge in " << i << " row and " << j << " col: ";
                    cin >> graph[i][j];
                }
                cout << "\n";
            }
        }

        void printGraph(void) {
            for(int i=0; i < vertices; i++) {
                for(int j=0; j < vertices; j++) {
                    cout << graph[i][j]<<" ";
                }
                cout << endl;
            }
        }

        void DFS(int v, bool visit[]) {
            visit[v] = true;
            cout << " " << v << endl; 

            for(int i=0; i < vertices; i++) {
                if(graph[v][i] == 1 && !visit[i]) 
                    DFS(i,visit);
            }
        }

        void depth_first_search() 
        {
            bool visit[vertices];
            for(int i=0; i < vertices; i++)
                visit[i] = false;
            for(int i=0; i < vertices; i++) {
                if(!visit[i])
                    DFS(i, visit);
            }
        }
        void breadth_first_search() {
            
            bool visited[vertices];
            
            
            queue<int> q1;
            for(int i=0; i < vertices; i++)
                visited[i] = false;
            for(int index=0; index < vertices; index++) 
            {
                if(!visited[index])
                {
                    q1.push(index);
                    visited[index] = true;
                    cout << " " << index << " ";
                    while(!q1.empty()) 
					{
                        int v = q1.front();
                        q1.pop();
                        for(int i=0; i < vertices; i++) 
                            if(graph[v][i] == 1 && !visited[i])
                            {
                                q1.push(i);
                                visited[i] = true;
                                
                            }
                    }
                }
            }
        }

    
        
  
};
int main() {
    int num;
    cout << "\nEnter number of vertices : ";
    cin >> num;
    Graph obj(num);
    obj.insert();
    obj.printGraph();
    cout<<endl<<" Perform BFS <<"<<endl;
    
    obj.breadth_first_search();
    
    cout<<endl<<" Perform DFS <<"<<endl;
    obj.depth_first_search();

    return 0;
}
