class Solution {
  int switch_non_val(vector<int>&nums)
  {
    int i = 1;
      for (int j = 2; j < nums.size();j++)
      {
        if (nums[j] == nums[i] && nums[j] != nums[i-1] || nums[j] != nums[i] && nums[j] != nums[i-1] )
        {
          nums[i+1] = nums[j];
          i++;
        }
      }
      return i+1;
  }
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2)
        return nums.size();
        return switch_non_val(nums);
    }
};