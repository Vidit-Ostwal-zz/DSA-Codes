class Solution {
public:
    int longestConsecutive(vector<int>& A) {
      
      set<int> st(A.begin(),A.end());
      vector<int> nums(st.begin(),st.end());
      
      
      if (!nums.size())
        return 0;
      
      
      sort(nums.begin(),nums.end());
      
      vector<int> dp(nums.size(),1);
      int answer = 1;
      
      for (int i = 1; i < nums.size(); i++)
      {
        if (nums[i] - nums[i-1] == 1)
          dp[i]  = 1 + dp[i-1];
        
        answer = max (answer, dp[i]);
      }
      return answer;
    }
};