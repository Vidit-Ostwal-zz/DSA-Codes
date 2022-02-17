class Solution {
  vector<vector<int>> answer;
  void solve(vector<int> candid,int target, int index,vector<int> temp)
  {
    if (target == 0)
    {
      answer.push_back(temp);
      return;
    }
    
    if (index < 0 || target < 0)
      return ;
    
    solve(candid,target,index-1,temp);
    
    temp.push_back(candid[index]);
    solve(candid,target-candid[index],index,temp);
  }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates,target,candidates.size()-1,{});
      return answer;
    }
};