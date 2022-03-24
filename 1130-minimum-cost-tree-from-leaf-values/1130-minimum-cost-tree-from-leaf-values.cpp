class Solution {
  vector<vector<int>> dp;
  int get_max(vector<int> arr, int st,int ed)
  {
    if (st == ed)
      return 0;
    
    if (dp[st][ed] != -1)
      return dp[st][ed];
    
    int maxi = INT_MAX;
    for (int i = st; i < ed; i++)
    {
      int left = get_max(arr,st,i);
      int right = get_max(arr,i+1,ed);
      
      int maxi1 = 0;
      int maxi2 = 0;
      
      for (int j = st; j <= i; j++)
        maxi1 = max(maxi1,arr[j]);
      
      for (int k = i+1; k <= ed; k++)
        maxi2 = max(maxi2,arr[k]);
      // cout << st << "   " << ed << "  " << left << "  " << right << "  "<< maxi1 << "  " << maxi2 << endl;
      
      maxi = min(maxi,left + right + maxi1*maxi2);
    }
    return dp[st][ed] = maxi;
  }
public:
    int mctFromLeafValues(vector<int>& arr) {
      dp = vector<vector<int>>(arr.size(),vector<int>(arr.size(),-1));
        return get_max(arr,0, arr.size()-1);
    }
};