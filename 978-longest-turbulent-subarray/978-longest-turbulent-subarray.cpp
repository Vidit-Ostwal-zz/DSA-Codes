class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector<int> temp;
      
      for (int i = 1; i < arr.size(); i++)
      {
        int it = arr[i] - arr[i-1];
        
        if (it > 0)
          temp.push_back(1);
        else if (it < 0)
          temp.push_back(-1);
        else
          temp.push_back(0);
      }
      
      vector<int> dp;
      int maxi = 0;
      for (int i = 0; i < temp.size(); i++)
      {
        if (i == 0 && temp[i])
          dp.push_back(1);
        else if (temp[i] == 0)
          dp.push_back(0);
        else
        {
          if (temp[i]*temp[i-1] == -1)
            dp.push_back(dp[dp.size()-1] + 1);
          else
            dp.push_back(1);
        }
        maxi = max(maxi,dp[dp.size()-1]);
      }
      return maxi + 1;
    }
};