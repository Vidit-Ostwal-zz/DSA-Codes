// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        int nos = pow(2,N);
        vector<int> answer;
        
        for (int i = 0; i < nos; i++)
        {
            int j = N-1;
            int temp = i;
            int sum = 0;
            
            while (j >= 0 && temp)
            {
                if (temp & 1)
                {
                    sum += arr[j];
                }
                j--;
                temp = temp >> 1;
            }
            answer.push_back(sum);
        }
        return answer;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends