class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_index = 0;
        int non_zero_index = 0;
      int temp;
      while (non_zero_index < nums.size())
      {
        while (zero_index < nums.size() && nums[zero_index] != 0 )
        {
          zero_index++;
        }
        if (non_zero_index > zero_index)
        {
          temp = nums[zero_index];
          nums[zero_index] = nums[non_zero_index];
          nums[non_zero_index] = temp;
        }
        non_zero_index++;
      }
    }
};