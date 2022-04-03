class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
      
      if (nums.size() == 1 && k%2)
        return -1;
      int maxi = 0;   
      for (int i=  0; i <= k  && i < nums.size();i++)
      {
        if (i == k-1)
          continue;
        else
        {
          maxi = max (maxi, nums[i]);
        }
      }
      return maxi;
    }
};