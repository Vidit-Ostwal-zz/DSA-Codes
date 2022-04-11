class Solution {
  // vector<vector<int>> dp;
  vector<int> dp;
//   int max_length(vector<int> arr, int diff, int i, int prev_i, bool flag)
//   {
//     if (i == arr.size())
//       return 0;
    
//     if (flag)
//     {
//       if (dp1[i] != -1)
//         return dp1[i];
//       return dp1[i] = max(max_length(arr,diff,i+1,prev_i,flag),1+max_length(arr,diff,i+1,i,!flag));
//     }
    
//     else
//     {
//       if (dp[i][prev_i] != -1)
//         return dp[i][prev_i];
//       else if (arr[i] - arr[prev_i] == diff)
//         return dp[i][prev_i] = max(max_length(arr,diff,i+1,prev_i,flag),1+max_length(arr,diff,i+1,i,flag));
//       else 
//         return dp[i][prev_i] = max_length(arr,diff,i+1,prev_i,flag);
//     }
//     return 0;
//   }
public:
    int longestSubsequence(vector<int>& arr, int difference) {
      // dp = vector<vector<int>>(arr.size(),vector<int>(arr.size(),-1));
      dp = vector<int>(arr.size(),1);
      //   return max_length(arr,difference,0,-1,true);
      
      unordered_map<int,int> map1;
      int maxi = INT_MIN;
      for (int i = 0; i < arr.size(); i++)
      {
        // cout << i << endl;
        int temp = arr[i] - difference;
        if (map1.find(temp) != map1.end())
          dp[i] = 1 + dp[map1[temp]];
        else
        {}
        maxi = max(maxi,dp[i]);
        map1[arr[i]]  = i;
      }
      return maxi;
    }
};