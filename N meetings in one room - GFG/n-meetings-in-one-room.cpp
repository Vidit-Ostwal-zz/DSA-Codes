// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // End Value and index
        
        // End time priority
        vector<pair<int,int>> vect;
        
        for (int i = 0; i < n; i++)
        {
            vect.push_back(make_pair(end[i],i));
        }
        
        sort(vect.begin(),vect.end());
        
        int st = vect[0].first;
        int max_meetings = 1;
        
        for (int i = 1; i < n; i++)
        {
            int end_time = vect[i].first;
            int start_time = start[vect[i].second];
            
            if (start_time > st)
            {
                max_meetings++;
                st = end_time;
            }
        }
        return max_meetings;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends