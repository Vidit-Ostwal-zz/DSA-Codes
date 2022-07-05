class Solution {
  /*Insertion Sort
  Time Complexity = O(N^2)
  Space Complexity = O(N)*/
  void insertion_sort(vector<int>&nums)
  {
    for (int i = 1; i < nums.size(); i++)
    {
      int j = i;
      while (j > 0 && nums[j] < nums[j-1])
      {
        int temp = nums[j];
        nums[j] = nums[j-1];
        nums[j-1] = temp;
        j--;
      }
    }
  }
public:
    void sortColors(vector<int>& nums) {
        // insertion_sort(nums);
      
      int zero_count = 0;
      int one_count = 0;
      
      for (int i = 0; i < nums.size(); i++)
      {
        if (nums[i] == 0)
          zero_count++;
        else if (nums[i] == 1)
          one_count++;
      }
      
      int j  =0;
      
      while (j < nums.size())
      {
        if (zero_count)
        {
          nums[j++] = 0;
          zero_count--;
        }
        else if (one_count)
        {
          nums[j++] = 1;
          one_count--;
        }
        else
        {
          nums[j++] = 2;
        }
      }
    }
};