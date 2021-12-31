class Solution {
public:
  
  void get_all_combinations(vector<int>& candidates, int target,int left, int index, vector<int> temp_vector, vector<vector<int>> & final_vector)
  {
    if (target <= 0)
    {
      if (target == 0 && left == 0)
      {
          final_vector.push_back(temp_vector);
      }
      return ;
    }
    if (index >= candidates.size() || left < 0)
    {
      return;
    }
    
    get_all_combinations(candidates, target,left, index+1, temp_vector, final_vector);
    temp_vector.push_back(candidates[index]);
    get_all_combinations(candidates,target-candidates[index],left-1,index+1,temp_vector,final_vector);
  }
  
    vector<vector<int>> combinationSum3(int k, int n) {
     
      vector<int> candidates;
      for (int i = 1 ;i < 10; i++)
      {
        candidates.push_back(i);
      }
      vector<vector<int>>  final_vector;
      vector<int> temp_vector;
      get_all_combinations(candidates,n,k,0,temp_vector,final_vector);
      
      return final_vector;
    }
};