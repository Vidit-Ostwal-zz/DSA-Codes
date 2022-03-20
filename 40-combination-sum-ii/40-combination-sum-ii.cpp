class Solution {
  map<vector<int>,bool> FV;
  vector<vector<int>> final_vector;
  
  void subset_sum(vector<int> candidates, int target, vector<int> temp, int index)
  {
    if (target == 0)
    {
      if (FV.find(temp) == FV.end())
      {
        FV[temp] = true;
        final_vector.push_back(temp);
      }
      return ;
    }
    
    if (index == candidates.size() || candidates[index] > target)
      return ;
    
    int temp_index = index;
    while (temp_index + 1 < candidates.size() && candidates[temp_index] == candidates[temp_index+1])
      temp_index++;
    
    subset_sum(candidates,target,temp,temp_index+1);
    /*No Occurences of it should be taken into account*/
    
    temp.push_back(candidates[index]);
    subset_sum(candidates,target-candidates[index],temp,index+1);
    
  }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(),candidates.end());
      
      if (candidates[candidates.size()-1]*candidates.size() < target)
        return {};
      
        subset_sum(candidates,target,{},0);
      return final_vector;
    }
};