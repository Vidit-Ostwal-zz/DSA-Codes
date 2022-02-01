class Solution {
public:
   /*
  Total there will be nums.size() + 1 numbers
  In sorted version it would be it at it's position like 1 will be at it's 1 index
  What about the number which is equal to nums.size () ignore it */
  
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
        /*correct_index is the right index for this value*/
        int correct_index = nums[i];
        /*if it's present over the right index then increase i otherwise swap*/
        if (nums[i] < nums.size() && nums[i] != nums[correct_index])
        {
          swap(nums[i],nums[correct_index]);
        }
        else
        {
          i++;
        }
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