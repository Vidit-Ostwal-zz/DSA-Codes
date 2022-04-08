class Solution {
  vector<vector<int>> dp_true;
  vector<vector<int>> dp_false;
  
  int max_possible1 (vector<int> nums, int f, int s, bool flag, int i, int c)
  {
    if (c == 2)
      return 0;
    
    if (nums.size() <= i)
      return INT_MIN;
    
    if (flag)
    {
      if (dp_true[i][c] != -1)
        return dp_true[i][c];
      
      int sum = 0;
      for (int id = 0; id < f && i + id < nums.size(); id++)
        sum += nums[i+id];
      if (f + i -1 < nums.size())
        return dp_true[i][c] = max(sum + max_possible1(nums,f,s,!flag,f+i,c+1),max_possible1(nums,f,s,flag,i+1,c));
      else
        return INT_MIN;
    }
    
     if (dp_false[i][c] != -1)
        return dp_false[i][c];
    
    int sum = 0;
      for (int id = 0; id < s && i + id < nums.size(); id++)
        sum += nums[i+id];
      if (s + i -1 < nums.size())
        return dp_false[i][c] = max(sum + max_possible1(nums,f,s,!flag,s+i,c+1),max_possible1(nums,f,s,flag,i+1,c));
      else
        return INT_MIN;
  }
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
      
      dp_true = vector<vector<int>>(nums.size(),vector<int>(2,-1));
       dp_false = vector<vector<int>>(nums.size(),vector<int>(2,-1));
      
      int maxi = max_possible1(nums,firstLen,secondLen,true,0,0);
      
      dp_true = vector<vector<int>>(nums.size(),vector<int>(2,-1));
       dp_false = vector<vector<int>>(nums.size(),vector<int>(2,-1));
      
      int maxi1 = max_possible1(nums,secondLen,firstLen,true,0,0);
      
        return max(maxi,maxi1);
    }
};