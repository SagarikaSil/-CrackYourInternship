// BFS of graph (using adjacency matrix)

// Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
// Note: One can move from node u to node v only if there's an edge from u to v and find the BFS traversal 
// of the graph starting from the 0th vertex, from left to right according to the graph. Also, you should 
// only take nodes directly or indirectly connected from Node 0 in consideration.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(int i, vector<int>* adj, vector<bool>& vis, vector<int>& v){
       queue<int> q;
       q.push(i);
       vis[i] = true;
       
       while(!q.empty()){
           int front = q.front();
           q.pop();
           v.push_back(front);
           
           for(int j=0; j<adj[front].size(); j++){
               int element = adj[front][j];
               if(!vis[element]){
                   q.push(element);
                   vis[element] = true;
               }
           }
       }                    
   }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V, false);
        vector<int> v;
       
        bfs(0, adj, vis, v);
         
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends