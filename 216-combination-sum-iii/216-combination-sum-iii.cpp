class Solution {
  vector<vector<int>> answer;
  
  void get_all_combinations(int k, int n, int curr,vector<int> temp)
  {
    if (k == 0 && n == 0)
    {
      answer.push_back(temp);
      return;
    }
    
    if (curr > n || curr > 9)
      return;
    
    get_all_combinations(k,n,curr+1,temp);
    
    temp.push_back(curr);
    get_all_combinations(k-1,n-curr,curr+1,temp);
  }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
      
      get_all_combinations(k,n,1,{});
      return answer;
    }
};