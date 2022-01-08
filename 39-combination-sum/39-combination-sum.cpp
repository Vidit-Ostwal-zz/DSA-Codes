class Solution {
public:
  
  /*
  Observations
  1> Repeatations of individuals allowed
  2> Candiadates are specifically different
  */
  
   vector<vector<int>> get_valid_combinations(vector<int> candidates, int target, vector<int> temp, int index)
  {
    /*Base Condition*/
    if (target == 0)
    {
       vector<vector<int>> answer;
      answer.push_back(temp);
      return answer;
    }
     
    if (target < 0 || index >= candidates.size())
    {
       vector<vector<int>> answer;
        return answer;
    }
    
    
    vector<vector<int>> vect1 = get_valid_combinations(candidates, target,temp, index+1);
     
    temp.push_back(candidates[index]);
    vector<vector<int>> vect2 = get_valid_combinations(candidates, target-candidates[index],temp, index);
     
     vect1.insert(vect1.end(),vect2.begin(),vect2.end());
     return vect1;
  }
  

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<int> temp;
      return get_valid_combinations(candidates,target,temp,0);
    }
};