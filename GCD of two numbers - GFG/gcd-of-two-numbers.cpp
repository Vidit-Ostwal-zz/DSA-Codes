// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution
{
	public:
	/*GCD does not change if we subtract the bigger number with smaller number*/
	/*We do not need to check for the higher number of smaller number The algo will remain same, just a iteration will increase, Have a dry run once*/
	/*For remembering purpose think that B is smaller and A is larger*/
    int gcd(int A, int B) 
	{ 
	    // code here
	    if (B == 0)
	    return A;
	    
	    return gcd(B,A%B);
	} 
};

// { Driver Code Starts.

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
        int A, B;
        cin >> A >> B;
        Solution ob;
       	cout <<  ob.gcd(A, B) << "\n";
    }
    return 0;
}  // } Driver Code Ends