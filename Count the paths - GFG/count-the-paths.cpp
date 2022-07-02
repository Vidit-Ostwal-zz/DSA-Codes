// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    unordered_map<int,vector<int>> mapofedges;
    vector<int> dp;
    // vector<bool> canvisit;
    void make_map (vector<vector<int>> &B)
    {
        for (int i = 0; i < B.size(); i++)
        {
            mapofedges[B[i][0]].push_back(B[i][1]);
        // mapofedges[B[i][1]].push_back(B[i][0]);
        }
    }
    
    int numberofways(int index, int desti)
    {
        if (index == desti)
        {
            return 1;
        }
        
        // if (dp[index] != -1)
        // {
        //     return dp[index];
        // }
        
        // canvisit[index] = false;
        
        int answer = 0;
        for (int i = 0; i < mapofedges[index].size(); i++)
        {
            answer += numberofways(mapofedges[index][i],desti);
        }
        
        // canvisit[index] = true;
        return dp[index] = answer;
    }
public:
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    
	    make_map(edges);
	    dp = vector<int>(n,-1); 
	   //canvisit = vector<bool> (n,true);
	    return numberofways(s, d);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends