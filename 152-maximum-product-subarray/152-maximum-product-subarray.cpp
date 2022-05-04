class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
      if (nums.size() == 0)
        return 0;
      
      int answer = nums[0];
      int temp_max = nums[0];
      int temp_min = nums[0];
      
      for (int i = 1; i < nums.size(); i++)
      {
        if (nums[i] < 0)
        {
          int temp = temp_max;
          temp_max = temp_min;
          temp_min = temp;
        }
        
        temp_max = max(nums[i], temp_max * nums[i]);
        temp_min = min(nums[i], temp_min * nums[i]);
        answer = max(temp_max,answer);
      }
      return answer;
    }
};