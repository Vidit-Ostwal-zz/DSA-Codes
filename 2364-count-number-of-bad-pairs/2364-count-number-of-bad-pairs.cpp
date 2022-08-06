class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
      
      long long count = 0;
      
      for (int i = 0; i < nums.size(); i++)
        nums[i] -= i;
      
      unordered_map<int,int> map1;
      // vector<int> dp(nums.size(),0);
      
      for (int i = 0; i < nums.size(); i++)
      {
        // count += map1[nums[i]].size();
        count += map1[nums[i]];
        map1[nums[i]]++;
        // map1[nums[i]].push_back(i);
      }
      return (long long)nums.size()*(nums.size()-1)/2 - count;
    }
};