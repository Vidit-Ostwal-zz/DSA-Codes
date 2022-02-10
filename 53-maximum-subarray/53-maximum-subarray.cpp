class Solution {
  
  /*
  Time Complexity = O(2^N)
  Space Complexity = O(N)
  */
  int recursive_solution(vector<int> nums, int index, int curr)
  {
    if (index == nums.size())
      return curr;
    
    /*
    At an index 3 decision varaibles
    1 > Don't include just stop there only.
    2 > Include and countinue 
    3 > start a new one from here
    */
    
    int temp1 = curr + nums[index];
    int temp2 = recursive_solution(nums,index+1,temp1);
    int temp3 = recursive_solution(nums,index+1,nums[index]);
    
    return max(curr,max(temp2,temp3));
    
  }
  
  int top_down_solution(vector<int> nums)
  {
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    
    /*For a index we can think as the closing bracket will be here*/
    for (int i = 1; i < nums.size(); i++)
    {
      /*Start a new one from here, add previous one and then start a new one
      If previous one is giving you a negative value then only option here is to have a fresh new start */
      int temp = max(nums[i],(dp[i-1] <= 0) ? 0 : dp[i-1]+nums[i]);
      if (temp <= 0)
        dp[i] = nums[i];
      else
        dp[i] = temp;
      
      cout << dp[i] << endl;
    }
    sort(dp.begin(),dp.end());
    return dp[nums.size()-1];
  }
  
  /*Kadane Algorithm O(N) Time Complexity
  int answer = INT_MIN;
      int temp = 0;
      for (int i = 0; i < nums.size();i++)
      {
        temp += nums[i];
        
        answer = max(answer,temp);
        if (temp <= 0)
          temp = 0;
      }
      return answer;
  */
public:
    int maxSubArray(vector<int>& nums) {
      /*Start by including the first case, a negative integer case can be there
        return recursive_solution(nums,0,0);*/
      return top_down_solution(nums);
    }
};