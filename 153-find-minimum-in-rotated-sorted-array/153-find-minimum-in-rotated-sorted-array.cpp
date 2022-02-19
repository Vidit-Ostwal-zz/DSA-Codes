class Solution {
  int Binary_Search(vector<int> nums)
  {
    int st = 0; 
    int ed = nums.size() -1;
    
    while (st <= ed)
    {
      int mid = st + (ed - st)/2;
      
      if (mid + 1 < nums.size() && nums[mid] > nums[mid+1])
        return mid;
      
      if (mid - 1 >= 0 && nums[mid-1] > nums[mid])
        return mid-1;
        
      else if (nums[mid] < nums[ed])
        ed = mid-1;
      
      else 
        st = mid+1;
    }
    return -1;
  }
public:
    int findMin(vector<int>& nums) {
        int index = Binary_Search(nums);
          return nums[(index+1) % nums.size()];
    }
};