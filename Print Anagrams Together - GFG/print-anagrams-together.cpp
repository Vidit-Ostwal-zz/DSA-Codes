// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        vector<string> copy_list(string_list.begin(),string_list.end());
        
        for (int i = 0; i < copy_list.size(); i++)
        {
            sort(copy_list[i].begin(),copy_list[i].end());
        }
        set <string> set_of_string(copy_list.begin(),copy_list.end());
        
        vector<vector<string>> answer_vector;
        set<string,greater <string>> ::iterator itr;
        for (itr = set_of_string.begin(); itr != set_of_string.end(); itr++)
        {
            vector<string> temp_vector;
            string temp_string = *itr;
            for (int j = 0 ;j < copy_list.size();j++)
            {
                if (!temp_string.compare(copy_list[j]))
                {
                    temp_vector.push_back(string_list[j]);
                }
            }
            answer_vector.push_back(temp_vector);
        }
        return answer_vector;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends