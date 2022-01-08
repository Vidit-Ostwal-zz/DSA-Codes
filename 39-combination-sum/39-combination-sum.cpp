class Solution {
public:
  
  /*
  Observations
  1> Repeatations of individuals allowed
  2> Candiadates are specifically different
  */
  
  void get_valid_combinations(vector<int> candidates, int target, vector<vector<int>>&answer, vector<int> temp, int index)
  {
    /*Base Condition*/
    if (target == 0)
    {
      answer.push_back(temp);
      return;
    }
    
    if (target < 0 || index >= candidates.size())
      return;
    
    
    get_valid_combinations(candidates, target, answer,temp, index+1);
    temp.push_back(candidates[index]);
    get_valid_combinations(candidates, target-candidates[index], answer,temp, index);
  }
  

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>answer;
      vector<int> temp;
      get_valid_combinations(candidates,target,answer,temp,0);
      return answer;
    }
};