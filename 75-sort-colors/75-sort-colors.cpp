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
        insertion_sort(nums);
    }
};