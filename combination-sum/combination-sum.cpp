class Solution {
public:
  vector<vector<int>> get_unique(vector<vector<int>> final_vector)
  {
    set<vector<int>> vector_set(final_vector.begin(),final_vector.end());
    vector<vector<int>> set_vector(vector_set.begin(),vector_set.end());
    return set_vector;
  }
  
  void get_all_combinations(vector<int>& candidates, int target,int index, vector<int> temp_vector, vector<vector<int>> & final_vector)
  {
    if (target <= 0)
    {
      if (target == 0)
      {
          final_vector.push_back(temp_vector);
      }
      return ;
    }
    if (index >= candidates.size())
    {
      return;
    }
    
    get_all_combinations(candidates, target, index+1, temp_vector, final_vector);
    temp_vector.push_back(candidates[index]);
    get_all_combinations(candidates,target-candidates[index],index,temp_vector,final_vector);
  }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      sort(candidates.begin(),candidates.end());
      vector<vector<int>>  final_vector;
      vector<int> temp_vector;
      get_all_combinations(candidates,target,0,temp_vector,final_vector);
      
      return final_vector;
    }
};