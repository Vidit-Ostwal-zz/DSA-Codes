class Solution {
  int top_down_solution(vector<int>& nums)
  {
    vector<int> reach(nums.size(),INT_MAX);
    int i = 0;
    reach[i] = 0;

    for (int k = 0; k < nums.size();k++)
    {
      int jump = nums[k]+k;
      for (int i = k+1; i <= jump && i < nums.size(); i++)
      {
        reach[i] = min(reach[k]+1,reach[i]);
      }
    }
    return reach[reach.size()-1];
  }
public:
    int jump(vector<int>& nums) {
        return top_down_solution(nums);
    }
};