// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int prefix_sum = 0;
        int answer = 0;
        unordered_map<int,int> prefix_map;
        
        prefix_map[0] = 0;
        
        for (int i = 0; i < n; i++)
        {
            prefix_sum += A[i];
            
            if (prefix_sum == 0)
            {
                answer = max(answer,i+1);
            }
            else if (prefix_map[prefix_sum] == 0)
            {
                prefix_map[prefix_sum] = i+1;
            }
            else
            {
                answer = max(answer,i+1 - prefix_map[prefix_sum]);
            }
        }
        
        return answer;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends