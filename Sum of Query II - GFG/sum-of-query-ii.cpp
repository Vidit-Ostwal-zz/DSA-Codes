// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        vector<int> temp;
        int to = 0;
        for (int i = 0; i < n; i++)
        {
            to += arr[i];
            temp.push_back(to);
        }
        
        vector<int> answer;
        for (int i = 0; i < 2*q;)
        {
            int a = queries[i]-1;
            int b = queries[i+1]-1;
            i = i + 2;
            int f = temp[b] - ((a-1 >= 0) ? temp[a-1] : 0);
          
            answer.push_back(f);
        }
        return answer;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n;
        int arr[n];
        for(int i = 0;i < n;i++)
            cin>>arr[i];
        cin>>q;
        int queries[2*q];
        for(int i = 0;i < 2*q;i += 2)
            cin>>queries[i]>>queries[i+1];
        
        Solution ob;
        vector<int> ans = ob.querySum(n, arr, q, queries);
        for(int u: ans)
            cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends