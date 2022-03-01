class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int st = 0; 
      int ed = nums.size()-1;
      
      while (st <= ed)
      {
        int mid = st + (ed - st)/ 2;
        if (mid > 0 && nums[mid] > nums[mid-1] && mid+1 < nums.size() && nums[mid] > nums[mid+1])
          return mid;
        
        /*Descending thing*/
        if (mid+1 < nums.size() && nums[mid] > nums[mid+1])
          ed = mid-1;
        
        /*Increasing Sequence*/
        else
          st = mid+1;
      }
      return -1;
    }
};