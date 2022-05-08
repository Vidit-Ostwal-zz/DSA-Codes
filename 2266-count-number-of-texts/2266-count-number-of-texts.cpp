class Solution {
  
public:
    int countTexts(string pressedKeys) {
      int MOD = pow(10,9) + 7;
      vector<int> dp(pressedKeys.size(),0);
      dp[0] = 1;
      
      // cout << pressedKeys[0] << "   " << dp[0] << endl;
      for (int i = 1; i < pressedKeys.length(); i++)
      {
        if (pressedKeys[i] != '7' && pressedKeys[i] != '9')
        {
          int j = i;
          j--;
          
          int temp = dp[i-1];
          temp = temp % MOD;
          
          int count = 2;
          
          while (count)
          {
            if (j>=0 && pressedKeys[j] == pressedKeys[i])
            {
              if (j-1 >= 0)
              {
                temp += dp[j-1];
                temp = temp % MOD;
              }
              else
              {
                temp++;
                temp = temp % MOD;
              }
            }
            else
              break;

            j--;
            count--;
          }
          
          dp[i] = temp;
      
        }
        else
        {
          int j = i;
          j--;
          
          int temp = dp[i-1];
          temp = temp % MOD;
          
          int count = 3;
          
          while (count)
          {
            if (j>=0 && pressedKeys[j] == pressedKeys[i])
            {
              if (j-1 >= 0)
              {
                cout << j << endl;
                temp += dp[j-1];
                temp = temp % MOD;
              }
              else
              {
                cout << j << endl;
                temp++;
                temp = temp % MOD;
              }
            }
            else
              break;

            j--;
            count--;
          }
          
          dp[i] = temp;
      
        }
        
        // cout << pressedKeys[i] << "   " << dp[i] << endl;
      }
      
      return dp[dp.size()-1];
    }
};