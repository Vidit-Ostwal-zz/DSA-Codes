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
        for (int i = 0; i < nums.size(); i++)
        {
          while (nums[i] != i && nums[i] != nums.size())
          {
            swap(nums[i],nums[nums[i]]);
          }
        }
      int i = 0 ;
      for (; i < nums.size(); i++)
      {
        if (i != nums[i])
          return i;
      }
      return i;
      
    }
};