class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int count = 1;
      int index = 0;
      
      for (int i = 1; i < nums.size(); i++)
      {
        if (nums[i] == nums[index])
          count++;
        else
          count--;
        
        if (count == 0)
        {
          index = i;
          count++;
        }
      }
      return nums[index];
    }
};