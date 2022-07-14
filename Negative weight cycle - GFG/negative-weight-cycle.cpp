// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Belmann Ford Algorithm
	    // Directed Graph with no negative Edge cycle 
	    // If Negative Edge Cycle is there then their is no shortest path
	    // Used to calculated shortest Path
	    // If Undirected make then directed by using two edges, again one edge conversion
	    // TC = (V*E)
	    
	    // Algo relax all the edges N-1 times and that will give the shortes path from the starting point
	    // if with another iteration distance reduces then their is a cycle
	    vector<long long> distance(n,INT_MAX);
	    distance[0] = 0;
	    // Distance to starting array is always Zero;
	    
	    // N - 1 edges
	    for (int i = 0; i < n; i++)
	    {
	        for (int j = 0; j < edges.size(); j++)
	        {
	            int st = edges[j][0];
	            int ed = edges[j][1];
	            int weight = edges[j][2];
	            
	            if (distance[st] + weight < distance[ed])
	            {
	                distance[ed] = distance[st] + weight;
	            }
	        }
	    }
	    
	    for (int j = 0; j < edges.size(); j++)
	    {
	        
	        int st = edges[j][0];
	        int ed = edges[j][1];
	        int weight = edges[j][2];
	        
	        if (distance[st] + weight < distance[ed])
	        {
	            return 1;
	        }
	    }
	    return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends