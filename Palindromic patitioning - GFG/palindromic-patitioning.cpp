// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    bool ispalindrome(string A,int i, int j)
    {
        while(i <= j)
        {
            if (A[i] != A[j])
            return false;
            
            i++;
            j--;
        }
        return true;
    }
    
    int minpart(string str, int i, int j)
    {
       
        if (i >= j)
        return 0;
        if (ispalindrome(str, i, j))
        return 0;
        int answer = INT_MAX;
        
        /*Breaking i to k and k+1 to j both inclusive*/
        for (int k = i; k < j;k++)
        {
            answer = min(answer,minpart(str,i,k)+minpart(str,k+1,j)+1);
        }
        return answer;
    }
    
    int minpartmemo(string str, int i, int j,vector<vector<int>>&dp)
    {
       
        if (i >= j)
        return 0;
        if (ispalindrome(str, i, j))
        return 0;
        
        if (dp[i][j] != -1)return dp[i][j];
        
        int answer = INT_MAX;
        
        /*Breaking i to k and k+1 to j both inclusive*/
        for (int k = i; k < j;k++)
        {
            int left = (dp[i][k] != -1) ? dp[i][k] : minpartmemo(str,i,k,dp);
            int right = (dp[k+1][j] != -1)? dp[k+1][j] : minpartmemo(str,k+1,j,dp);
            
            answer = min(answer,left+right+1);
        }
        return dp[i][j] = answer;
    }
public:
    int palindromicPartition(string str)
    {
        vector<vector<int>> dp (str.length(),vector<int>(str.length(),-1));
        return minpartmemo(str,0,str.length()-1,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends