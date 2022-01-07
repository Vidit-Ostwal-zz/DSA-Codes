class Solution {
public:
    int findNumbers(vector<int>& nums) {
      int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
          int digits = log10(nums[i]);
          if (digits & 1)
          {
            count++;
          }
        }
      return count;
    }
};