class Solution {
  int Binary_Search(vector<int> nums,int target)
  {
    int st = 0;
    int end = nums.size()-1;
    
    while (st <= end)
    {
      int mid = st + (end -st)/2 ;
      if (nums[mid] == target)
        return mid;
      
      if (nums[mid] > target)
        end  = mid -1;
      
      else
        st = mid + 1;
    }
    return -1;
  }
public:
    int search(vector<int>& nums, int target) {
        return Binary_Search(nums,target);
    }
};