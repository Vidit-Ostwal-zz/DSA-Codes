class Solution {
public:
  int binary_search(vector<int> nums, int target)
  {
    int start = 0;
    int end = nums.size()-1;
    
    while (start <= end)
    {
      int mid = (start + end) / 2;
      
      if (nums[mid] == target)
      {
        return mid;
      }
      if (nums[mid] > target)
      {
        end = mid - 1;
      }
      else
      {
        start = mid + 1;
      }
    }
    return start;
  }
  /*Find the smallest index equal to or greater than the given target*/
    int searchInsert(vector<int>& nums, int target) {
        return binary_search(nums,target);
    }
};