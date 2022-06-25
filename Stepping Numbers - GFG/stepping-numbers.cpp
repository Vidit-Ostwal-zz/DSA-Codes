// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    
    
    int Helper(int n, int m, int curr)
    {
        int answer = 0;
        
        if (curr > m)
        {
            return 0;
        }
        
        if (curr <= m && curr >= n)
        {
            // cout << curr << endl;
            answer++;
        }
        
        int last_digit = curr % 10;
        
        if (last_digit == 0)
        {
            answer += Helper(n,m,curr*10 + 1);
        }
        else if (last_digit == 9)
        {
            answer += Helper(n,m,curr*10 + 8);
        }
        else
        {
            answer += Helper(n,m,curr*10 + last_digit+1);
            answer += Helper(n,m,curr*10 + last_digit-1);
        }
        return answer;
    }
public:
    int steppingNumbers(int n, int m)
    {
        int count = 0;
        for (int i = 1; i <= 9; i++)
        {
            count += Helper(n,m,i);
        }
        
        if (0 >= n && m >= 0)
        {
            count++;
        }
        return count;
    }
};


// { Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}

  // } Driver Code Ends