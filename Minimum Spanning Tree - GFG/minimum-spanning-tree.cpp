// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	
	unordered_map<int,vector<pair<int,int>>> u1;
	
	/*Make the unordered_pair for the same*/
	void make_tree (int N, vector<vector<int>> adj[])
	{
	    for (int i = 0; i < N; i++)
	        for (int j = 0; j < adj[i].size(); j++)
	            {
	                u1[i].push_back(make_pair(adj[i][j][0],adj[i][j][1]));
	                u1[adj[i][j][0]].push_back(make_pair(i,adj[i][j][1]));
	            }
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        make_tree (V,adj);
        /*visited veector keeps tracks of whether the element has been included in MST*/
        /*Distance vector denotes the minimum weight to this
        Parent keeps track of the parent of the node*/
        vector<bool> visited (V,false);
        vector<int> dist(V,INT_MAX);
        vector<int> parent(V,-1);
        
        dist[0] = 0;
        
        for (int count = 0; count < V - 1; count++)
        {
            // cout << count << endl;
            int i = -1;
            int mini = INT_MAX;
            
            for (int k = 0; k <  dist.size(); k++)
            {
                if (!visited[k] && mini > dist[k])
                {
                    mini = dist[k];
                    i = k;
                }
            }
            
            visited[i] = true;
            
            for (int a = 0; a < u1[i].size(); a++)
            {
                int vi = u1[i][a].first;
                int w = u1[i][a].second;
                
                if (!visited[vi] && dist[vi] > w)
                {
                    dist[vi] = w;
                    parent[vi] = i;
                }
            }
        }
        
        int answer = 0;
        
        for (int i = 0; i < dist.size(); i++)
        {
            answer += dist[i];
        }
        return answer;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends