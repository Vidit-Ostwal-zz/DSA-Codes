// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    
    /* Time Compplexity = O(N + E)
    Space Complexity = O(N) + O(N)*/
    vector<int> final_vector;
    
    void dfs(int i, vector<bool>& visited_vector, vector<int> adj[])
    {
        final_vector.push_back(i);
        for (int j = 0; j < adj[i].size(); j++)
        {
            if (visited_vector[adj[i][j]])
            {
                visited_vector[adj[i][j]] = false;
                dfs(adj[i][j],visited_vector,adj);
            }
        }
    }
    
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        /*Initializing a visited vector for all*/
        vector<bool> visited_vector(V,true);
        
        for (int i = 0; i < V; i++)
        {
            if (visited_vector[i])
            {
                visited_vector[i] = false;
                dfs(i,visited_vector,adj);
            }
        }
        return final_vector;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends