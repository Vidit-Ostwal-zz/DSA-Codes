class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++)
        {
          auto it = find(nums.begin(),nums.end(),target-nums[i]);
          
          if (it != nums.end())
          {
            int index = it - nums.begin();
          if (index != i)
          {
            return {i,index};
          }
          else
          {
            auto it1 = find(nums.begin()+ i+1,nums.end(),target-nums[i]);
            if ( it1 != nums.end())
            {
              int index = it1 - nums.begin();
              return {i,index};
            }
          }
          }
        }
      return {};
    }
};