class Solution {
public:
  
  void swap (int &A, int &B)
  {
    int temp = A;
    A = B;
    B = temp;
  }
  
  
    int missingNumber(vector<int>& nums) {
      int i = 0;
      while (i < nums.size())
      {
        int correct_index = nums[i];
        
        if (nums[i] < nums.size() && nums[i] != nums[correct_index])
          swap(nums[i],nums[correct_index]);
        
        else
          i++;
      }
      
      i = 0;
      for (; i < nums.size(); i++)
      {
        if (i != nums[i])
          return i;
      }
      return i;
      
    }
};