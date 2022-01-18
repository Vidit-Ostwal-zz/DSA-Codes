// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    int count(string S, int i, int j, bool flag,unordered_map <string,int> &map)
    {
        int mod = 1003;
        if (i > j)
        return 0;
        
        if (i == j)
        {
            if (flag)
            {
                if (S[i] == 'T')
                return 1;
                
                else
                return 0;
            }
            else
            {
                if (S[i] == 'F')
                return 1;
                
                else
                return 0;
            }
        }
        string temp = to_string(i) + " " + to_string(j) + " " + to_string(flag);
        
        if (map.find(temp) != map.end()) return map[temp];
        
        int answer = 0;
        /*Breaking from i to k-1 and k+1 to j*/
        for (int k = i+1; k < j; k)
        {
            int lt = count(S,i,k-1,true,map) %mod;
            int lf = count(S,i,k-1,false,map)%mod;
            int rt = count(S,k+1,j,true,map)%mod;
            int rf = count(S,k+1,j,false,map)%mod;
            
            if (S[k] == '|')
            {
                if (flag)
                answer += ((lt * rt)%mod + (lf * rt)%mod + (lt * rf)%mod)%mod;
                
                else
                answer += (lf * rf)%mod;
            }
            else if (S[k] == '&')
            {
                if (flag)
                 answer += (lt * rt)%mod ;
                
                else
                 answer += ((lf * rf)%mod + (lf * rt)%mod + (lt * rf)%mod)%mod;
            }
            else if (S[k] == '^')
            {
                if (flag)
                 answer += ((lf * rt)%mod + (lt * rf)%mod)%mod;
                
                else
                answer += ((lt * rt)%mod + (lf * rf)%mod)%mod;
            }
            k = k+2;
        }
        return map[temp] = answer%mod;
    }
    
    
    
    
public:
    int countWays(int N, string S){
        unordered_map <string,int> map;
        return count(S,0,N-1,true,map);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends