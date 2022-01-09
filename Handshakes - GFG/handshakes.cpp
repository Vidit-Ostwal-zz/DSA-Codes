// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:


/*
Time Complexity : divide and conquer O(nlogn) * O(n)
Space Complexity : Recursive Function Call 
Maximum Height of the tree is O(N)*/
int count_handshakes(int N)
{
    if (N <= 2)
    {
        return N-1;
    }
    int count = 0;
    for (int i = 1; i < N;)
    {
        if (i == 1 || i == N-1)
        {
            count += count_handshakes(N-2);
        }
        else
        {
            count += count_handshakes(i-1)*count_handshakes(N -1 -i);
        }
        i = i+2;
    }
    return count;
}
    int count(int N){
        return count_handshakes(N);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends