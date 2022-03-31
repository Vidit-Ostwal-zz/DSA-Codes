// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    /*Time Complexity = O(N) Number of Nodes + O(E) number of Edges in adjancy List
    Space Complexity = O(N) + O(N) Queue and O(N) Color Array*/
    
    bool BFS (int V, vector<int> adj[])
    {
        /*This will be used as a visited Array*/
        vector<int> color(V,-1);
        int flag = 0;
        for (int i = 0; i < color.size(); i++)
        {
            /*Not Visited Yet*/
            /*Disconneted Graph Entry*/
            if (color[i] == -1)
            {
                queue<int> q;
                q.push(i);
                color[i] = flag;
                
                while (!q.empty())
                {
                    flag = (flag) ? 0 : 1;
                    int size = q.size();
                    while (size > 0)
                    {
                        int index = q.front();
                        q.pop();
                        
                        for (int i = 0; i < adj[index].size(); i++)
                        {
                            if (color[adj[index][i]] == -1)
                            {
                                color[adj[index][i]] = flag;
                                q.push(adj[index][i]);
                            }
                            else
                            {
                                if (color[adj[index][i]] != flag)
                                    return false;
                            }
                        }
                        size--;
                    }
                }
            }
        }
        return true;
    }
    
     /*Time Complexity = O(N) Number of Nodes + O(E) number of Edges in adjancy List
    Space Complexity = O(N) + O(N) Queue and O(N) Color Array*/
    
    bool DFS_traversal(int index, vector<int> adj[], vector<int>& color, int flag)
    {
        color[index] = flag;
        flag = (flag) ? 0 : 1;
        
        for (int i = 0; i < adj[index].size(); i++)
        {
            if (color[adj[index][i]] == -1)
            {
                if (!DFS_traversal(adj[index][i],adj,color,flag))
                    return false;
            }
            else
            {
                if (color[adj[index][i]] != flag)
                    return false;
            }
        }
        return true;
    }

    
    bool DFS (int V, vector<int> adj[])
    {
        vector<int> color(V,-1);
        for (int i = 0; i < color.size(); i++)
        {
            if (color[i] == -1)
            {
                /*Disconnected Graph Call No effect of flag function*/
                if (!DFS_traversal(i,adj,color,0))
                {
                    return false;
                }
            }
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    //return BFS(V,adj);
	    return DFS(V,adj);
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends