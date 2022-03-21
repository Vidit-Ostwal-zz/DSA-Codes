class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
      unordered_map<int,vector<int>> map;
      
      int count = 0;
      for (int i =0 ; i < nums.size(); i++)
      {
        if (map.find(nums[i]) == map.end())
          map[nums[i]].push_back(i);
        else
        {
          vector<int> temp(map[nums[i]].begin(),map[nums[i]].end());
          for (int j= 0 ;j < temp.size(); j++)
          {
            if (((temp[j] * i) % k) == 0)
              count++;
          }
          map[nums[i]].push_back(i);
        }
      }
      return count;
    }
};