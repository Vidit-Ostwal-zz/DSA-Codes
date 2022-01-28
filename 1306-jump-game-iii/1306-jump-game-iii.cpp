class Solution {
  bool top_down_solution(vector<int>& nums,int index)
  {
    vector<bool> already_reach(nums.size(),true);
    queue<int> q;
    q.push(index);
    
    while(!q.empty())
    {
      
      int index = q.front();
      q.pop();
      
      already_reach[index] = false;
      
      if (index + nums[index] < nums.size() && already_reach[index+nums[index]]) q.push(index+nums[index]);
      
      if (index - nums[index] >= 0 && already_reach[index-nums[index]]) q.push(index - nums[index]);
    }
    for (int i = 0; i < already_reach.size();i++)
    {
      if (!already_reach[i] && nums[i] == 0)
        return true;
    }
    return false;
  }
public:
    bool canReach(vector<int>& arr, int start) {
        return top_down_solution(arr,start);
    }
};