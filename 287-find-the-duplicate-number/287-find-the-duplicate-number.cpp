class Solution {
public:
  // Cyclic Sort Approach
    int findDuplicate(vector<int>& nums) {
      int i = 0;
      while (i < nums.size())
      {
        int correct_index = nums[i]-1;
        
        if (nums[i] < nums.size() && nums[i] != nums[correct_index])
          swap(nums[i],nums[correct_index]);
        
        else
          i++;
      }
      return nums[nums.size()-1];
    }
};