class Solution {
  vector<vector<int>> dp;
  vector<int> suffix;
  int len;
  
  void find_suffix (string floor)
  {
    int i = floor.length()-1;
    
    suffix[i] = floor[i] - '0';
    i--;
    while (i >= 0)
    {
      suffix[i] = suffix[i+1] + (floor[i] - '0');
      i--;
    }
  }
  
  int dp_memo(string floor, int index,int num)
  {
    if (num == 0)
      return suffix[index];
    
    if (index >= floor.length())
      return 0;

    if (dp[index][num] != -1)
      return dp[index][num];
    
    return dp[index][num] = min(dp_memo(floor,index+len,num-1), dp_memo(floor,index+1,num) + floor[index] - '0');
  }
  
  int top_down(string floor, int num, int len)
  {
    vector<vector<int>> dp(num+1,vector<int>(floor.length(),0));
    
    for (int i = 0; i <= num; i++)
    {
      for (int j = 0; j < floor.length(); j++)
      {
        if (i == 0 && j == 0)
          dp[i][j] = floor[j] - '0';
        
        else if (i == 0)
          dp[i][j] = floor[j] - '0' + dp[i][j-1];
        
        else if (j == 0)
          dp[i][j] = 0;
          
        else 
          dp[i][j] = min(dp[i][j-1] + floor[j] - '0',(j-len >= 0) ? dp[i-1][j-len] : 0);
      }
     
    }
    return dp[num][floor.length()-1];
  }
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
      
      if (carpetLen == 1)
      {
        int count = 0;
        for(int i =0; i < floor.length(); i++)
        {
          if (floor[i] - '0')
            count++;
        }
        return max(0,count-numCarpets);
      }
      
      return top_down(floor, numCarpets, carpetLen);
      len = carpetLen;
      suffix = vector<int>(1001,0);
      dp = vector<vector<int>>(1001, vector<int>(1001,-1));
      
      find_suffix(floor);
      
      return dp_memo(floor,0,numCarpets);
    }
};