class Solution {
public:
  
  /*Time Compleixty = O(2^N)
  Space Complexity = O(N) Recursion Stack Space*/
  int top_down_solution(vector<int> text1, vector<int> text2)
  {
    int result = 0;
    vector<vector<int>> dp(text1.size()+1,vector<int> (text2.size()+1,-1));
    for (int i = 0; i <= text1.size();i++)
    {
      for (int j = 0; j <= text2.size(); j++)
      {
        if (i == 0 || j == 0)
          dp[i][j] = 0;
        
        else if (text1[i-1] == text2[j-1])
          {
              dp[i][j] = 1 + dp[i-1][j-1];
              result = max(result,dp[i][j]);
          }
          
        else
          dp[i][j] = 0;
      }
    }
    return result;
  }
  
  
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        return top_down_solution(nums1,nums2);
    }
};