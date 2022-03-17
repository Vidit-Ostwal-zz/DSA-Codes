// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  /*Time Complexity =  O(N) + O(E)
  Space Complexity = O(2*N)*/
  
  /*In DFS you change the vector when the DFS on that is called*/
  bool check_self_DFS(vector<int>&vis, vector<int>&curr_vis, int index,vector<int> adj[])
  {
      vis[index] = 1;
      curr_vis[index] = 1;
      
      for (int i = 0; i < adj[index].size(); i++)
      {
          /*Two Cases either the element is already visited or not visited*/
          
          /*Not Visited*/
          if (vis[adj[index][i]] == 0)
          {
              if (check_self_DFS(vis,curr_vis,adj[index][i],adj))
              {
                  return true;
              }
          }
          
          /*Visited*/
          else
          {
              if (curr_vis[adj[index][i]] == 1)
              {
                  return true;
              }
          }
      }
      
      curr_vis[index] = 0;
      return false;
  }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        /*Visited vector and current path visited vector*/
        vector<int> vis(V,0);
        vector<int> cur_vis(V,0);
        
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                if (check_self_DFS(vis,cur_vis,i,adj))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends