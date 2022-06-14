class Solution {
  vector<vector<int>> dp;
  long long Helper(string A, string B, int indexA, int indexB)
  {
    if (indexA == A.length() && indexB == B.length())
      return 0;
    
    if (dp[indexA][indexB] != -1)
      return dp[indexA][indexB];
    
    if (indexA < A.length() && indexB < B.length() && A[indexA] == B[indexB])
      return dp[indexA][indexB] = Helper(A,B,indexA+1,indexB+1);
    
    if (indexA < A.length() && indexB < B.length())
      return dp[indexA][indexB] = 1 + min(Helper(A,B,indexA+1,indexB),Helper(A,B,indexA,indexB+1));
    
    if (indexA < A.length() && indexB == B.length())
      return dp[indexA][indexB] = 1 + Helper(A,B,indexA+1,indexB);
    
    return dp[indexA][indexB] = 1 + Helper(A,B,indexA,indexB+1);
  }
public:
    int minDistance(string word1, string word2) {
      dp = vector<vector<int>> (word1.length()+1,vector<int>(word2.length()+1,-1));
        return Helper(word1,word2,0,0);
    }
};