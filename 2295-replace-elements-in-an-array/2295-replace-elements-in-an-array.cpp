class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> u1;
      
      for (int i = 0; i < nums.size(); i++)
        u1[nums[i]] = i;
      
      for (int i = 0; i < operations.size(); i++)
      {
        int key = operations[i][0];
        int index = u1[key];
        u1.erase(key);
        nums[index] = operations[i][1];
        u1[nums[index]] = index;
      }
      return nums;
    }
};