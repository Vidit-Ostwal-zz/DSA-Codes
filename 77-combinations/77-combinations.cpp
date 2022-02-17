class Solution {
  vector<vector<int>> answer;
  
  void solve(int n,int k,vector<int> temp)
  {
    if (k == 0)
    {
      answer.push_back(temp);
      return ;
    }
    
    if (n == k)
    {
      temp.push_back(n);
      solve(n-1,k-1,temp);
      return;
    }
    
    if (n > k)
    {
      solve(n-1,k,temp);
      temp.push_back(n);
      solve(n-1,k-1,temp);
      return;
    }
  }
public:
    vector<vector<int>> combine(int n, int k) {
        solve(n,k,{});
      return answer;
    }
};