class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      if (nums.size() < 3)
        return {};
      
      int smallest_diff = INT_MAX;
      
      sort(nums.begin(),nums.end());
      set<vector<int>> set1;
      int final_sum = 1000005;
      
      for (int i = 0; i < nums.size()-2; i++)
      {
        int first = nums[i];
        int start = i+1;
        int end = nums.size()-1;
        
        while (start < end)
        {
          int sum = first + nums[start] + nums[end];
          if (sum  == target)
          {
            return sum;
          }
          else if (sum > target)
          {
            end--;
          }
          else
          {
            start++;
          }
          if (abs(sum - target) < abs(final_sum-target))
            final_sum = sum;
        }
      }
      return final_sum;
    }
};