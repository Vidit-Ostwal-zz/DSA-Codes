// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    /*In Bfs Modified when we iterate in adjaceny list and if we visited a already visited 
    Node, then why is it visted, if its from the path, we came from then no problem, but if it is visited 
    from another path, then there is a cycle
    That's why a check with the prev
    
    Traversal BFS
    Time Complexity = O(N) visited array loop + O(E) loop over all the adjancey matrix edges 
    Space Complexity = O(N) visited bool array and O(N) queue
    */
    bool bfs_modi(int i, vector<int> adj[],vector<bool>&vis)
    {
        queue<pair<int,int>> qt;
        qt.push({i,-1});
        vis[i] = false;
        
        while (!qt.empty())
        {
            int index = qt.front().first;
            int prev = qt.front().second;
             qt.pop();
             
            for (int i = 0; i < adj[index].size() ; i++)
            {
                if (vis[adj[index][i]])
                {
                    vis[adj[index][i]] = false;
                    qt.push({adj[index][i],index});
                }
                else
                {
                    if (adj[index][i] != prev)
                    return true;
                }
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V,true);
        
        for (int i = 0; i < vis.size(); i++)
        {
            if (vis[i])
            {
                if (bfs_modi(i,adj,vis))
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends