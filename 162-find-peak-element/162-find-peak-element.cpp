class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
      if (nums.size() == 1)
        return 0;
      
      int st = 0;
      int ed = nums.size()-1;
      
      while (st < ed)
      {
        int mid = st + (ed-st)/2;
        
        if (mid+1 < nums.size() && mid-1 >= 0 && nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1])
          return mid;
        
        else if (nums[mid] < nums[mid+1])
          st = mid+1;
        
        else
          ed = mid;
        
      }
      return st;
    }
};