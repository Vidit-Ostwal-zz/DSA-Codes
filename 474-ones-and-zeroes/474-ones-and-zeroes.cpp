class Solution {
  vector<int> ones;
  vector<int> zeros;
  vector<vector<vector<int>>> dp;
  void helper (vector<string> strs)
  {
    for (int i = 0; i < strs.size(); i++)
    {
      string temp = strs[i];
      
      int count = 0;
      for (int j = 0; j < temp.length(); j++)
        if (temp[j] - '0')
          count++;
      
      ones.push_back(count);
      zeros.push_back(temp.length()-count);
    }
  }
  
  
  int get_largest(int m, int n, int i)
  {
    if (i == ones.size() || ((m == 0) && n == 0))
      return 0;
    
    if (dp[i][m][n] != -1)
      return dp[i][m][n];
    
    if (m - zeros[i] >= 0 && n - ones[i] >= 0)
      return dp[i][m][n] = max(1 + get_largest(m - zeros[i],n - ones[i],i+1), get_largest(m,n,i+1));
    
    return dp[i][m][n] = get_largest(m,n,i+1);
  }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        helper(strs);
      dp = vector<vector<vector<int>>> (strs.size(), vector<vector<int>>(m+1,vector<int>(n+1,-1)));
      return get_largest(m,n,0);
    }
};