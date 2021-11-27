class Solution {
public:
void get_combinations(vector<int> candidates, int target, vector<int> temp_vector, vector<vector<int>>& final_vector)
  {
    if (target == 0)
    {
      sort(temp_vector.begin(),temp_vector.end());
      if (final_vector.end() == find(final_vector.begin(),final_vector.end(),temp_vector))
      {
         final_vector.push_back(temp_vector);
      }
      return ;
    }
    if (target < 0)
    {
      return ;
    }
  for (int i = 0; i < candidates.size(); i++)
  {
    temp_vector.push_back(candidates[i]);
    get_combinations(candidates,target-candidates[i],temp_vector,final_vector);
    temp_vector.pop_back();
  }
  }
  
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> final_vector;   
      get_combinations(candidates,target,{},final_vector);
      return final_vector;
    }
};
