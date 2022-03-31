// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    /*Depth First Search Algorithm*/
	/*Time Complexity = O(N) + O(E)
	Space Complexity = O(N) */
	
	
	void DFS(vector<int> adj[], int index, vector<bool>& vis, stack<int> & st)
	{
	    vis[index] = false;
	    
	    for (int i = 0; i < adj[index].size(); i++)
	    {
	        if (vis[adj[index][i]])
	        {
	            DFS(adj,adj[index][i],vis,st);
	        }
	    }
	    st.push(index);
	}
	
	
	
	vector<int> BFS(vector<int> adj[], vector<int> count_id, queue<int> &q)
	{
	    vector<int> answer;
	    while (!q.empty())
	    {
	        int index = q.front();
	        q.pop();
	        answer.push_back(index);
	        
	        for (int i = 0; i < adj[index].size(); i++)
	        {
	            count_id[adj[index][i]]--;
	            if (count_id[adj[index][i]] == 0)
	            {
	                q.push(adj[index][i]);
	            }
	        }
	    }
	    return answer;
	}
	
	
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
		{
	    vector<bool> vis(V,true);
	    stack<int> st;
	    
	    for (int i = 0; i < V; i++)
	    {
	        if (vis[i])
	        {
	            DFS(adj,i,vis,st);
	        }
	    }
	    vector<int> answer;
	    while (!st.empty())
	    {
	        answer.push_back(st.top());
	        st.pop();
	    }
	    return answer;
	    
	    vector<int> count_id(V,0);
	    for (int i = 0; i < V; i++)
	    {
	        for (int j = 0; j < adj[i].size(); j++)
	        {
	            count_id[adj[i][j]]++;
	        }
	    }
	    
	    queue<int> q;
	    for (int i = 0; i < count_id.size(); i++)
	    {
	        if (!count_id[i])
	        {
	            q.push(i);
	        }
	    }
	   
	   return BFS(adj,count_id,q);
	    
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends