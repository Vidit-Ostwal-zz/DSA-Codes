class Solution {
  
  int kadane_algorithm(vector<int> nums)
  {
    int sum = 0;
    int answer = 0;
    int i = 0; 
    
    while (i < nums.size())
    {
      /*0 should not be included*/
      if (nums[i] == 0)
        nums[i] = INT_MIN;
      
      
      sum += nums[i];
      answer = max(answer,sum);
      
      if (sum < 0)
        sum = 0;
      
      i++;  
    }
    return answer;
    
  }
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        return kadane_algorithm(nums);
    }
};