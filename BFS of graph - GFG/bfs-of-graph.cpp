// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    /*Time Complexity = O(N (visited Array Loop overall) + E (edges looping overall through queue))
    Space Complexity = visited Array + queue = O(N) + O(N)
    N is number of nodes
    E is number of edges */
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        /*Final Vector declaration*/
        vector<int> final_vector;
        
        /*Visited vector declaration*/
        vector<bool> visited_vector(V,true);
    
        /*Iteration over visited vector*/
        for (int i = 0; i < visited_vector.size(); i++)
        {
            /*Index Not visited yet, do a BFS traversal over it */
            if (visited_vector[i])
            {
                /*Queue Declaration*/
                queue<int> qt;
                
                /*Change the visited_vector whenever you push in the queue for the first time*/
                qt.push(i);
                visited_vector[i] = false;
                
                while (!qt.empty())
                {
                    int temp = qt.front();
                    
                    /*Push in final vector as soon as you pop it from the queue for the first time*/
                    qt.pop();
                    final_vector.push_back(temp);
                    
                    for (int j= 0; j < adj[temp].size(); j++)
                    {
                        /*Check whether this element is already visited or not If not visited then only push it into the queue*/
                        if (visited_vector[adj[temp][j]])
                        {
                            visited_vector[adj[temp][j]] = false;
                            qt.push(adj[temp][j]);
                        }
                    }
                }
            }
            return final_vector;
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
}  // } Driver Code Ends