// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        string answer= "" ;
        
        int index = 0;
        bool flag = true;
        
        int min_size = INT_MAX;
        for (int i = 0; i < N; i++)
            {
                if (min_size > arr[i].length())
                {
                    min_size = arr[i].length();
                }
            }
            
        while (flag && index < min_size)
        {
            char temp = arr[0][index];
            for (int i = 0; i < N; i++)
            {
                if (temp != arr[i][index])
                {
                    flag = false;
                }
            }
            if (flag)
            {
                answer += temp;
            }
            index++;
        }
        if (!answer.length())
        {
            return "-1";
        }
        return answer;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends