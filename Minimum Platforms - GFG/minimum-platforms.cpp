// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        map<int,int> map1;
        
        for (int i = 0; i < n; i++)
        {
            map1[arr[i]]++;
            map1[dep[i]+1]--;
        }
        
        int max_req = 0;
        int curr_req = 0;
        
        auto it = map1.begin();
        
        while (it != map1.end())
        {
            curr_req += it -> second;
            max_req = max(max_req,curr_req);
            it++;
        }
        return max_req;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends