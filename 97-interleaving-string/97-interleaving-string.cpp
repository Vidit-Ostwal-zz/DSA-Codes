class Solution {
  vector<vector<vector<int>>> dp;
  bool canHappen(string a, string b, string c, int i, int j, int k)
  {
    if (i == a.length() && j == b.length() && k == c.length())
      return true;
    
    if (dp[i][j][k] != -1)
      return (dp[i][j][k] == 0) ? false : true;
    
    bool flag = false;
    if (j != b.length() && a[i] == b[j])
      flag = flag || canHappen(a,b,c,i+1,j+1,k);
    
    if (k != c.length() && a[i] == c[k])
      flag = flag || canHappen(a,b,c,i+1,j,k+1);
    
    dp[i][j][k] = (flag) ? 1 : 0;
    return flag;
  }
public:
    bool isInterleave(string s1, string s2, string s3) {
      dp = vector<vector<vector<int>>> (s3.length()+1,vector<vector<int>>(s2.length()+1,vector<int>(s1.length()+1,-1)));
      if (s3.length() != s1.length() + s2.length())
        return false;
      
        return canHappen(s3,s2,s1,0,0,0);
    }
};