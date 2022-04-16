class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
      
      int mini = INT_MAX;
      
      for (int i = 0; i < nums.size(); i++)
        mini  = min(mini,abs(nums[i]));
      
      int answer = INT_MIN;
      
      for (int i = 0; i < nums.size(); i++)
        if (abs(nums[i]) == mini)
          answer = max(answer,nums[i]);
      
      return answer;
    }
};