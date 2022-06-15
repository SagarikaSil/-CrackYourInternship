#include <iostream>
using namespace std;
#include <queue>

void BFS(int** graph, int v, int sv, bool* visited){
    queue<int> pending_vertices;
    
    pending_vertices.push(sv);
    visited[sv]=true;

    while(!pending_vertices.empty()){
        int currentVertex = pending_vertices.front();
        pending_vertices.pop();
        cout<<currentVertex<<" ";
        for(int i=0;i<v;i++){
            if(i==currentVertex)
                continue;
            if(graph[currentVertex][i]==1&&!visited[i]){
                pending_vertices.push(i);
                visited[i]=true;
            }
        }
    }
}

int main(){
    int v,e;
    cin>>v>>e;

    int **graph = new int*[v];
    for(int i=0; i<v; i++){
        graph[i] = new int[v];
        for(int j=0; j<v; j++){
            graph[i][j]=0;
        }
    }

    for(int i=0; i<e; i++){
        int f,s;
        cin>>f>>s;
        graph[f][s]=1;
        graph[s][f]=1;
    }

    bool *visited = new bool[v];
    for(int i=0; i<v; i++){
        visited[i]=false;
    }

    for(int i=0; i<v; i++){
        if(!visited[i])
            BFS(graph,v,i,visited);
    }
}