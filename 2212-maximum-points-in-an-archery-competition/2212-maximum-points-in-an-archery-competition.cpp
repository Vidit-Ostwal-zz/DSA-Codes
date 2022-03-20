class Solution {
  vector<int> answer;
  int maxi = INT_MIN;
  int left;
  
  void recur(int numArrows, vector<int> alice, int profit,int index, vector<int> Bob)
  {
    if (numArrows == 0 || index >= alice.size())
    {
      if (maxi < profit)
      {
        left = numArrows;
        maxi = profit;
        answer = Bob;
      }
      return ;
    }
    
    recur(numArrows,alice,profit,index+1,Bob);
    
    int req_arrow = alice[index] + 1 ;
    
    if (req_arrow <= numArrows)
    {
      Bob[index] = req_arrow;
      numArrows -= req_arrow; 
      recur(numArrows,alice,profit+index,index+1,Bob);
    }
  }
  
  vector<int> top (int num,vector<int> aliceArrows)
  {
    vector<vector<int>> dp(num+1,vector<int>(aliceArrows.size(),0));
    
    for (int i = 0; i <= num; i++)
    {
      for (int j = 0; j < aliceArrows.size(); j++)
      {
        if (i == 0 || j == 0)
        {}
        
        else
          dp[i][j] = max((i > aliceArrows[j]) ? j + dp[i - aliceArrows[j]-1][j-1] : INT_MIN, dp[i][j-1]);
        
        /*cout << dp[i][j] << "   " ;*/
      }
      /*cout << endl;*/
    }
    
    vector<int>Bob(aliceArrows.size(),0);
    
    int j= Bob.size()-1;
    int count = 0;
    int i = num;
    while (j >= 0)
    {
      if (j == 0 || dp[i][j] == dp[i][j-1] || i <= aliceArrows[j])
        Bob[j] = 0;
      else
      {
        Bob[j] = aliceArrows[j] + 1;
        count += Bob[j];
        i -= (aliceArrows[j] +1); 
      }
      j--;
    }
    Bob[0] += (num - count);
    return Bob;
  }
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
      vector<int>Bob(aliceArrows.size(),0);
      
      /*return top(numArrows,aliceArrows);*/
        recur(numArrows,aliceArrows,0,0,Bob);
      answer[0] += left;
      
      for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << "   " ;
      
      cout << endl;
      return answer;
    }
};