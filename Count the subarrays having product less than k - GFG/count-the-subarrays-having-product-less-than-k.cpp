// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        /*Sliding window approach*/
        long long temp = 1;
        int answer = 0;
        for (int start = 0,end = 0 ; end < n ; end++)
        {
            temp *= a[end];
            
            while (start < end && temp >= k)
            {
                temp /= a[start];
                start++;
            }
            
            if (temp < k)
            {
                answer += end - start + 1;
            }
        }
        return answer;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends