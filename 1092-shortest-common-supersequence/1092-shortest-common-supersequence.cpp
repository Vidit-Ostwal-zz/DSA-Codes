class Solution {
public:

  string top_down_solution(string text1, string text2)
  {
    vector<vector<int>> dp(text1.length()+1,vector<int> (text2.length()+1,-1));
    for (int i = 0; i <= text1.length();i++)
    {
      for (int j = 0; j <= text2.length(); j++)
      {
        if (i == 0 || j == 0)
          dp[i][j] = 0;
        
        else
          dp[i][j] = (text1[i-1] == text2[j-1]) ? 1 + dp[i-1][j-1] : max(dp[i-1][j],dp[i][j-1]);
      }
    }
    int a = text1.length();
    int b = text2.length();
    string answer = "";
    while (a && b)
    {
        if (text1[a-1] == text2[b-1])
        {
            answer += text1[a-1];
            a--;
            b--;
        }
        else
        {
            if (dp[a-1][b] > dp[a][b-1])
            {
              answer += text1[a-1];
              a-- ;
            }
            else {
              answer += text2[b-1];
              b-- ;
          }
        }
    }
    cout << a << "  " << b << endl;
    while (a > 0)
    {
      answer += text1[a-1];
      a--;
    }
    while (b > 0)
    {
      answer += text2[b-1];
      b--;
    }
    reverse(answer.begin(),answer.end());
    return answer;
    
  }
  
  
    string shortestCommonSupersequence(string str1, string str2) {
        return top_down_solution(str1,str2);
    }
};