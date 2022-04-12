class Solution {
    vector<vector<int>> moves;
  vector<vector<int>> dp;
  
  int MOD = 1000000007;

  int count (int jump, int st)
  {
    // cout << jump << endl;
    if (jump == 0)
      return 1;
    
    if (dp[jump][st] != -1)
      return dp[jump][st];
    
    
    int sum = 0;
    for (int i = 0; i < moves[st].size(); i++)
    {
      sum += count(jump-1,moves[st][i])%MOD;
      sum = sum%MOD;
    }
    return dp[jump][st] = sum;
  }
  
  public:
    int knightDialer(int n) {
      moves.push_back({4,6});
      moves.push_back({6,8});
      moves.push_back({7,9});
      moves.push_back({4,8});
      moves.push_back({0,3,9});
      moves.push_back({});
      moves.push_back({0,1,7});
      moves.push_back({2,6});
      moves.push_back({1,3});
      moves.push_back({2,4});
      
      dp = vector<vector<int>> (n,vector<int>(10,-1));
      int sum = 0;
      
      for (int i = 0; i < 10; i++)
      {
        sum += count(n-1,i)%MOD;
        sum = sum % MOD;
      }
      return sum;
    }
};