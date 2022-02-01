class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
      
      while (i < nums.size())
      {
        if (nums[i] > 0)
        {
          int correct_index = nums[i] - 1;
        if (correct_index < nums.size() && nums[i] > 0 && nums[i] != nums[correct_index])
        {
          swap(nums[i],nums[correct_index]);
        }
        else
        {
          i++;
        }
        }
        else
        {
          i++;
        }
        
      }
      
      for (int i = 0; i < nums.size(); i++)
      {
        if (nums[i] != i+1)
          return i+1;
      }
      return nums.size()+1;
  
    }
};